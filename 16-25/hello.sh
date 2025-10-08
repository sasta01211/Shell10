#!/bin/bash
# Display username, time/date, who is logged on, and asterisks

echo "Username: $USER"
echo "*********"
echo "Date and Time: $(date)"
echo "*********"
echo "Logged on users:"
who
echo "*********"
