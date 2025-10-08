#!/bin/bash
# Change file names passed as arguments to lowercase

for file in "$@"; do
  if [ -f "$file" ]; then
    lower=$(echo "$file" | tr 'A-Z' 'a-z')
    mv "$file" "$lower"
  fi
done
echo "Renamed all files to lowercase."
