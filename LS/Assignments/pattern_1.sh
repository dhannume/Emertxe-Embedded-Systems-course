#!/bin/bash

<<doc
Name: Venkatesan N
Date: 25-Nov-22
Description: To create a pattern of numbers
Sample Input:4
Sample Output:1
              1 2 
              1 2 3 
              1 2 3 4

doc

# read the input for size of the pattern

read -p "Enter the size of pattern required: " n

#initiate first loop for incrementing row

for i in `seq $n`
do

#iniiate second loop for incrementing column

    for j in `seq $i`
    do

#print the ourput
       echo -n "$j "
    done
    echo

done

