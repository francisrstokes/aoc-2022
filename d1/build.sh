#!/bin/bash

INC="../inc"

PART1=("part1.c")
PART2=("part2.c")

PART1_O=$(echo $PART1 | sed 's/\.c/\.o/g')
PART2_O=$(echo $PART2 | sed 's/\.c/\.o/g')

for file in ${PART1[@]}; do
    gcc -Wall -I"$INC" -c $file
done
gcc -Wall -o part1.exe $PART1_O

for file in ${PART2[@]}; do
    gcc -Wall -I"$INC" -c $file
done
gcc -Wall -o part2.exe $PART2_O
