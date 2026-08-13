#!/usr/bin/env python3
import subprocess
import sys
from pathlib import Path

BUILD_DIR = Path("build")
ROOT_DIR = Path(__file__).resolve().parent


def die(msg: str) -> None:
    print(f"Error: {msg}", file=sys.stderr)
    sys.exit(1)


def to_target_name(arg: str) -> str:
    looks_like_path = arg.endswith(".cpp") or "/" in arg or Path(arg).is_file()
    if not looks_like_path:
        return arg

    p = Path(arg)
    if not p.is_file():
        die(f"path '{arg}' does not exist")

    rel = p.resolve().relative_to(ROOT_DIR)
    rel_noext = rel.with_suffix("")
    return str(rel_noext).replace("/", "_")


def main() -> None:
    if len(sys.argv) < 2:
        die("usage: ./run.py <target|path> [args...]")

    target = to_target_name(sys.argv[1])
    prog_args = sys.argv[2:]

    if not BUILD_DIR.exists():
        print("No build/ found, configuring...")
        subprocess.run(["cmake", "-G", "Ninja", "-B", str(BUILD_DIR)], check=True)

    build = subprocess.run(["cmake", "--build", str(BUILD_DIR), "--target", target])
    if build.returncode != 0:
        die(f"build failed for target '{target}'")

    matches = list((BUILD_DIR / "bin").rglob(target))
    if not matches:
        die(
            f"built target '{target}' but couldn't locate its binary under {BUILD_DIR}/bin"
        )
    if len(matches) > 1:
        die(f"multiple binaries matched '{target}': {matches}")

    binary = matches[0]

    print("Build Successful...")

    try:
        result = subprocess.run([str(binary), *prog_args])
    except KeyboardInterrupt:
        sys.exit(130)
    sys.exit(result.returncode)


if __name__ == "__main__":
    main()
