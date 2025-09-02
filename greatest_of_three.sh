#!/bin/bash
# Script to find greatest of three numbers

if [ $# -ne 3 ]; then
  echo "Usage: $0 num1 num2 num3"
  exit 1
fi

if [ $1 -ge $2 ] && [ $1 -ge $3 ]; then
  echo "Greatest number is: $1"
elif [ $2 -ge $1 ] && [ $2 -ge $3 ]; then
  echo "Greatest number is: $2"
else
  echo "Greatest number is: $3"
fi
