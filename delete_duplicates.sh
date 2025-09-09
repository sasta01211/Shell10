#!/bin/bash
# Script to delete files in dir1 if same file with same content exists in dir2

if [ $# -ne 2 ]; then
  echo "Usage: $0 dir1 dir2"
  exit 1
fi

for file in "$1"/*; do
  fname=$(basename "$file")
  if [ -f "$2/$fname" ] && cmp -s "$file" "$2/$fname"; then
    echo "Deleting $file (duplicate of $2/$fname)"
    rm "$file"
  fi
done
