#!/usr/bin/bash

# Take only the first row which contains all the letters
head -1 data.dat | \
# Make a column out of the row
tr --squeeze-repeats ' '  '\n' | \
# Count and output all unique letters in the column
uniq --count | \
# Remove leading newlines
awk '{$1=$1;print}' | \
# The first row is invalid, do not use it
tail --lines=+2
