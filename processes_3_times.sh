#!/bin/bash
# Script to display processes every 30 sec, only 3 times

for i in 1 2 3
do
  echo "----- Process list ($i) -----"
  ps
  sleep 30
done
