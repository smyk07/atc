#!/usr/bin/env python3
import re
import sys
from pathlib import Path

INCLUDE_RE = re.compile(r'^\s*#\s*include\s+"([^"]+)"')
PRAGMA_ONCE_RE = re.compile(r"^\s*#\s*pragma\s+once")

UTIL_DIR = Path("util")


def resolve_include(name: str, current_dir: Path) -> str:
    local = current_dir / name
    if local.is_file():
        return str(local)
    util_path = UTIL_DIR / name
    if util_path.is_file():
        return str(util_path)
    return str(local)


def process_file(filename: str, seen: set, out: list) -> None:
    if filename in seen:
        return
    seen.add(filename)

    p = Path(filename)
    current_dir = p.parent

    try:
        with open(filename, "r") as f:
            lines = f.read().splitlines()
    except OSError as e:
        print(f"Error: could not open '{filename}': {e}", file=sys.stderr)
        sys.exit(1)

    for line in lines:
        if PRAGMA_ONCE_RE.match(line):
            continue
        m = INCLUDE_RE.match(line)
        if m:
            inc_file = resolve_include(m.group(1), current_dir)
            out.append(f"// Start: {inc_file} ---")
            process_file(inc_file, seen, out)
            out.append(f"// End: {inc_file} ---")
        else:
            out.append(line)


def main() -> None:
    if len(sys.argv) < 2:
        print("Error: usage: ./includer.py <input_file> [output_file]", file=sys.stderr)
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2] if len(sys.argv) > 2 else "includer_o.cpp"

    if not Path(input_file).is_file():
        print(f"Error: Input file '{input_file}' does not exist.", file=sys.stderr)
        sys.exit(1)

    out: list[str] = []
    process_file(input_file, set(), out)

    Path(output_file).write_text("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
