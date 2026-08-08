#!/bin/bash

INPUT_FILE="$1"

OUTPUT_FILE="${2:-includer_o.cpp}"

if [ ! -f "$INPUT_FILE" ]; then
  echo "Error: Input file '$INPUT_FILE' does not exist." >&2
  exit 1
fi

awk '
  function process_file(filename,    line, match_arr, inc_file, current_dir) {
    if (filename in seen) return;
    seen[filename] = 1;

    if (filename ~ /\//) {
        current_dir = filename;
        sub(/\/[^\/]+$/, "", current_dir);
        current_dir = current_dir "/";
    } else {
        current_dir = "";
    }

    while ((getline line < filename) > 0) {
        if (line ~ /^[[:space:]]*#[[:space:]]*pragma[[:space:]]+once/) {
            continue;
        }

        if (line ~ /^[[:space:]]*#[[:space:]]*include[[:space:]]+"[^"]+"/) {
            match(line, /"[^"]+"/, match_arr);
            inc_file = substr(match_arr[0], 2, length(match_arr[0]) - 2);
            inc_file = current_dir inc_file;
            print "// --- Inline Start: " inc_file " ---"
            process_file(inc_file);
            print "// --- Inline End: " inc_file " ---"
        } else {
            print line;
        }
    }
    close(filename);
  }
  BEGIN {
    process_file("'"$INPUT_FILE"'");
  }
' >"$OUTPUT_FILE"
