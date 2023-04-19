#!/bin/bash

<<doc

Name: N. Venkatesan
Date: 14-Dec-22
Description: To Use a recursive function to print each argument passed to the function
Sample Input: ./recursion.sh 1 12 123 1234 12345 123456
Sample output: 
1
12
123
1234
12345
123456

doc


if [ $# -gt 0 ]  #To check whether CLAs passed or not.
then
	arr=($@)  #All CLAs are stored in array arr.
	n=0
	function recursive()
	{
		echo "$1"   #Printing only the first argument.
		let n=$n+1  #To end the recursive after all the arguments are considered.
		if [ $n -lt ${#arr[@]} ]  #To recurse the function till all elements are printed through the recursive function.
		then
			recursive ${arr[@]: $n}   #Giving arguments to the function recursive using array.
		else
			return   #To come out from recursive function after all CLAs are printed one by one.
		fi
	}
	recursive $1   #Calling the function first time for once.
else
	echo "Error : Pass the arguments through command line."
fi
