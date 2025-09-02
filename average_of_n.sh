#!/bin/bash
# Script to calculate average of n numbers

read -p "Enter count of numbers: " n
sum=0

for (( i=1; i<=n; i++ ))
do
  read -p "Enter number $i: " num
  sum=$((sum + num))
done

avg=$(echo "$sum / $n" | bc -l)
echo "Average = $avg"
