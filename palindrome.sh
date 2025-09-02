#!/bin/bash
# Script to check palindrome

read -p "Enter string: " str
rev=$(echo $str | rev)

if [ "$str" == "$rev" ]; then
  echo "Palindrome"
else
  echo "Not Palindrome"
fi
