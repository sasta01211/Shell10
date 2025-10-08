#!/bin/bash
# Remove all blank spaces from a text file and redirect to output.txt

if [ $# -ne 1 ]; then
  echo "Usage: $0 filename"
  exit 1
fi

if [ ! -f "$1" ]; then
  echo "File not found!"
  exit 1
fi

tr -d '[:space:]' < "$1" > output.txt
echo "Output saved to output.txt"
