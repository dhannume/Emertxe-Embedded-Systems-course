#!/bin/bash

<<doc

Name: N. Venkatesan
Date: 15-Dec-22
Description: for each directory in the $PATH, display the number of executable files in that directory
Sample Input:./executable_path.sh
Sample output: 
Current dir: /usr/local/sbin
current count: 0
Current dir: /usr/local/bin
current count: 0
Current dir: /usr/sbin
current count: 205
Current dir: /usr/bin
current count: 1889
Current dir: /sbin
current count: 187
Current dir: /bin
current count: 159
Current dir: /usr/games
current count: 5
Current dir: /usr/local/games
current count: 0
Total – 2445

doc

arr=(`printenv PATH | tr ":" " "`)  #Storing all the contents of PATH environment variable in an array using tr command through piping to separate the elements and store each directory as one element in an array.
total=0  #To get the overall count of executable files in PATH env var.
for i in ${arr[@]}   #Accessing each elements one by one
do
	if [ -d $i ]  #Checking whether the directory is present or not.
	then
		cd $i   #Changing current working directory to the directory path which is present in PATH environment variable.
		count=0  #To get the count of the number of executable files present in the directory.
		for j in `ls`  #Accessing the contents of the directory.
		do
			if [ -f $j -a -x $j ]  #Checking whether it is an executable file or not.
			then
				let count=$count+1   #Getting the count of all the executable files present.
			fi
		done
		echo -e "Current dir: $i\nCurrent count: $count"  #To print current working directory and number of executable files present in it.
		let total=$total+$count   #getting the total value of the executable files present in the PATH env var.
	fi
done
echo "Total - $total"   #To print the overall executable files in whole PATH env var.
