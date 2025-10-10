#!/bin/bash
# Concatenate two strings and perform simple calculator operations

echo "String Concatenation:"
read -p "Enter first string: " s1
read -p "Enter second string: " s2
res="$s1$s2"
echo "Concatenated string: $res"
echo "Length: ${#res}"

echo "\nSimple Calculator:"
read -p "Enter first number: " n1
read -p "Enter operator (+ - * /): " op
read -p "Enter second number: " n2

case $op in
  +) echo "Result: $((n1 + n2))";;
  -) echo "Result: $((n1 - n2))";;
  \*) echo "Result: $((n1 * n2))";;
  /) echo "Result: $((n1 / n2))";;
  *) echo "Invalid operator";;
esac
