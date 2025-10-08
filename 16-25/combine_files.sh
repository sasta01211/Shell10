#!/bin/bash
# Combine three text files into one and show word count

if [ $# -ne 3 ]; then
  echo "Usage: $0 file1 file2 file3"
  exit 1
fi

cat "$1" "$2" "$3" > combined.txt
wc -w combined.txt
