#!/bin/bash
# Script to print length of string argument

if [ $# -ne 1 ]; then
  echo "Usage: $0 string"
  exit 1
fi

echo "Length of \"$1\" = ${#1}"
