#!/bin/bash
# Script to check if input is number or string

read -p "Enter input: " inp

if [[ $inp =~ ^[0-9]+$ ]]; then
  echo "It is a Number"
else
  echo "It is a String"
fi
