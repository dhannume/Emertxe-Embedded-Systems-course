#!bin/bash

<<doc

Name: N. Venkatesan
Date: 14-Dec-22
Description: To convert all jpg files to a user mentioned name
Sample Input:
Sample output: 

doc

if [ $# -eq 1 ]  #To check if CLA is passed or not
then
	arr=(`ls *.jpg`) #Storing all the jpg files of present directory in an array

	for i in ${arr[@]}
	do
		x=`echo "$i" | cut -d "." -f1 | tr -cd [:digit:]` #To retain only number and storing it in a variable x.
		b=.jpg
        mv "$i" "$1$x$b"
	done
	echo "All .jpg files in current directory is renamed as"
	ls
else
	echo "Error : Please pass the prefix name through command line."
fi
