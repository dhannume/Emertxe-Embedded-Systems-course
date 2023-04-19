#!/bin/bash

<<doc

Name: N. Venkatesan
Date: 14-Dec-22
Description: to check if a filesystem is mounted
Sample Input:
Sample output: 

doc

if [ $# -eq 0 ]
then
    echo "Error : Please pass the name of the file-system through command line."
else

function mount
{
flag=0
df | tr -s " " | cut -d " " -f1,4,5 > details.txt
filesys=(`cut -d " " -f1 details.txt`) #filesystem
empty=(`cut -d " " -f2 details.txt`) #free space
percent=(`cut -d " " -f3 details.txt`) #percentage of space used
len=${#empty[@]} #number of file systems mounted


for i in `seq 1 $((len-1))`
  do
     if [ ${filesys[i]} == $1 ]
       then
       a=${empty[i]}
       b=${percent[i]}
       flag=`expr $flag + 1` 
       break
   fi
  done

if [ $flag -eq 0 ]
 then 
  echo "Filesystem $1 not mounted"  
else 
 echo "Filesystem $1 is $b used with $a kB free"
fi
rm *.txt
}

mount $1
fi
