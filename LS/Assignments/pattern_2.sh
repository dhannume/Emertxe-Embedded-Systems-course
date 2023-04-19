#!/bin/bash

<<doc
Name: Venkatesan N
Date: 26-Nov-22
Description: To create a pattern of incremental numbers
Sample Input:4
Sample Output:1
              2 3
              4 5 6 
              7 8 9 10

doc

# Read input for the size of the pattern

read -p "Enter the size of pattern: " n

#initialise the variable to be printed

a=0

#first loop for inrementing the row

for i in `seq $n`
do
    #second loop for incrementing the columns
    for j in `seq $i`
    do
        #increment the variable

        a=$((a+1))
#print the variable to create the pattern
       echo -n "$a "

    done
    echo

done

