#!/bin/bash
# Script to calculate factorial

read -p "Enter a number: " num
fact=1

for (( i=1; i<=num; i++ ))
do
  fact=$((fact * i))
done

echo "Factorial = $fact"
