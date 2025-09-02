#!/bin/bash
# Script to count characters and words in each line

if [ $# -ne 1 ]; then
  echo "Usage: $0 filename"
  exit 1
fi

lineno=1
while IFS= read -r line
do
  words=$(echo $line | wc -w)
  chars=$(echo $line | wc -c)
  echo "Line $lineno: Words=$words, Characters=$chars"
  lineno=$((lineno+1))
done < "$1"
