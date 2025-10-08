#!/bin/bash
# Check the spelling of any text document given as an argument

if [ $# -ne 1 ]; then
  echo "Usage: $0 filename"
  exit 1
fi

if [ ! -f "$1" ]; then
  echo "File not found!"
  exit 1
fi

aspell list < "$1" | sort -u
