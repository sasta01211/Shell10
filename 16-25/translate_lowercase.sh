#!/bin/bash
# Translate all characters in a text file to lowercase

if [ $# -ne 1 ]; then
  echo "Usage: $0 filename"
  exit 1
fi

if [ ! -f "$1" ]; then
  echo "File not found!"
  exit 1
fi

tr 'A-Z' 'a-z' < "$1" > lower.txt
echo "Translated to lowercase and saved as lower.txt"
