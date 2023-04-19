#!/bin/bash

<<doc

Name: N. Venkatesan
Date: 14-Dec-22 
Description: To count the number of user ids in given range
Sample Input:
Sample output: 

doc

usrid=(`cut -d ":" -f3 /etc/passwd`)  #Storing all users userids present in the system in one array.
if [ $# -gt 0 ]  #Checking if cla is passed or not
then
	if [ $# -eq 1 ]  #If only one cla is passed then print error
	then
		echo "Error : Please pass 2 arguments through CL.
		Usage : ./30_user_ids.sh 100 200"
	elif [ $1 -gt $2 ]    #If 1st cla is greater than 2nd cla then print error.
	then
		echo "Error : Invalid range. Please enter the valid range through CL."
	else
		count=0  #initialized a variable to count the number of users present in that range.
		for i in ${usrid[@]}  #accessing all the elements of the array which are userids one by one.
		do
			if [ $i -ge $1 -a $i -le $2 ]   #If the userid is within that range then we need to count it.
			then
				let count=$count+1
			fi
		done
		echo "Total count of user ID between $1 to $2 is : $count"
	fi
else  #If no cla is given then usrids are checked with default range between 500 to 10000.
	count=0
	for i in ${usrid[@]}
	do
		if [ $i -ge 500 -a $i -le 10000 ]
		then
			let count=$count+1
		fi
	done
	echo "Total count of user ID between 500 to 10000 is: $count"
fi
