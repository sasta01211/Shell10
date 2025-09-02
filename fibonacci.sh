#!/bin/bash
# Script to print Fibonacci series

read -p "Enter n: " n
a=0
b=1

echo "Fibonacci series: "
for (( i=0; i<n; i++ ))
do
  echo -n "$a "
  fn=$((a + b))
  a=$b
  b=$fn
done
echo
