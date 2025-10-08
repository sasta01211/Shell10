#!/bin/bash
# Write even lines to evenfile and odd lines to oddfile

if [ $# -ne 1 ]; then
  echo "Usage: $0 filename"
  exit 1
fi

awk 'NR % 2 == 0 {print > "evenfile"} NR % 2 == 1 {print > "oddfile"}' "$1"
echo "Separated into evenfile and oddfile"
