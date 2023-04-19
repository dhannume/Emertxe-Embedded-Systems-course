#!/bin/bash

<<doc

Name: N. Venkatesan
Date: 14-Dec-22 
Description: to print the contents of a folder without using ls command
Sample Input: ./output_ls.sh
Sample output: Assignments Classwork

doc

if [ $# -gt 0 ]  #Checking whether cla is passed or not
then
	cont=($@)   #Storing all CLAs in an array.
	for i in ${cont[@]}   #Accessing all elements of an array
	do
		if [ -d $i ]   #To check whether the directory is present or not.
        then
			cd $i  #Going to that directory which is given as CLA. Note, kindly give the absolute path from the second cla.
			echo "`pwd`:"     #Showing the present working directory and then it's contents
		    echo *   #Listing the contents of that directory without using ls command
		else
			echo "$0: Cannot access ‘$i’ : No such a file or directory."
		fi
	done
else
	echo *
fi
