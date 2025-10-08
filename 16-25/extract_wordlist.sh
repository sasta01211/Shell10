#!/bin/bash
# Extract a wordlist from a text file after spell checking and encryption

if [ $# -ne 1 ]; then
  echo "Usage: $0 filename"
  exit 1
fi

if [ ! -f "$1" ]; then
  echo "File not found!"
  exit 1
fi

aspell list < "$1" | sort -u > wordlist.txt
base64 wordlist.txt > wordlist.enc
echo "Wordlist created as wordlist.txt and encrypted version as wordlist.enc"
