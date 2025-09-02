#!/bin/bash
# Script to check prime

read -p "Enter a number: " num
if [ $num -le 1 ]; then
  echo "Not Prime"
  exit
fi

for (( i=2; i<=num/2; i++ ))
do
  if (( num % i == 0 )); then
    echo "Not Prime"
    exit
  fi
done

echo "Prime"
