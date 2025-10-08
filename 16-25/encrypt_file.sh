#!/bin/bash
# Encrypt any text file using base64 encoding

if [ $# -ne 1 ]; then
  echo "Usage: $0 filename"
  exit 1
fi

if [ ! -f "$1" ]; then
  echo "File not found!"
  exit 1
fi

base64 "$1" > "$1.enc"
echo "File encrypted as $1.enc"
