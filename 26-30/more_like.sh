#!/bin/bash
# Simple script like 'more' command - shows 15 lines at a time

read -p "Enter your name: " name
read -p "Enter file name: " file

if [ ! -f "$file" ]; then
  echo "File not found!"
  exit 1
fi

echo "Hello $name, displaying file contents..."

lines=$(wc -l < "$file")
start=1
while [ $start -le $lines ]; do
  end=$((start + 14))
  sed -n "${start},${end}p" "$file"
  start=$((end + 1))
  if [ $start -le $lines ]; then
    read -p "Press Enter to continue..."
  fi
done
