#!/bin/bash
# Delete all even-numbered lines in a text file

if [ $# -ne 1 ]; then
  echo "Usage: $0 filename"
  exit 1
fi

awk 'NR % 2 == 1' "$1" > oddlines.txt
echo "Even lines deleted. Output saved in oddlines.txt"
