#!/bin/bash
# Replace all occurrences of character c with string chr in a given string

read -p "Enter a string: " s
read -p "Enter the character to replace: " c
read -p "Enter replacement string: " chr

new_s=$(echo "$s" | sed "s/$c/$chr/g")
count=$(echo "$s" | grep -o "$c" | wc -l)

echo "Modified string: $new_s"
echo "Number of replacements: $count"
