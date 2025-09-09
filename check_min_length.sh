#!/bin/bash
# Script to check if string has at least 5 characters

read -p "Enter a string: " str

if [ ${#str} -lt 5 ]; then
  echo "String must have at least 5 characters"
else
  echo "Valid string: $str"
fi
