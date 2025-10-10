#!/bin/bash
# Count vowels, spaces, characters, symbols, and lines in a text file

if [ $# -ne 1 ]; then
  echo "Usage: $0 filename"
  exit 1
fi

if [ ! -f "$1" ]; then
  echo "File not found!"
  exit 1
fi

vowels=$(grep -o -i '[aeiou]' "$1" | wc -l)
spaces=$(grep -o ' ' "$1" | wc -l)
chars=$(wc -m < "$1")
symbols=$(grep -o '[^[:alnum:][:space:]]' "$1" | wc -l)
lines=$(wc -l < "$1")

echo "Vowels: $vowels"
echo "Spaces: $spaces"
echo "Characters: $chars"
echo "Symbols: $symbols"
echo "Lines: $lines"
