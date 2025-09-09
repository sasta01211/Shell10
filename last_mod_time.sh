#!/bin/bash
# Script to show last modification time of a file

if [ $# -ne 1 ]; then
  echo "Usage: $0 filename"
  exit 1
fi

if [ -f "$1" ]; then
  stat -c %y "$1"
else
  echo "File not found!"
fi
