#!/bin/bash
# Script to count number of files in each subdirectory

for dir in */; do
  [ -d "$dir" ] || continue
  count=$(find "$dir" -type f | wc -l)
  echo "$dir : $count files"
done
