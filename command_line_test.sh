#!/bin/bash

<<doc

Name: N. Venkatesan
Date: 16-Dec-2022
Description: to create a software with 3 options which can enabel signup, login and to take a MCQ test
Sample Input:
Sample output: 

doc

clear

function uservalid
{
flag=0
num=`cat user.csv | wc -l` #number of users that have signed up
existname=`cat user.csv` #usernames stored in an array
for user in ${existname[@]}
  do
    if [ "$name" == "$user" ] #match user input with names in database
     then
      flag=`expr $flag + 1` #increament if match
    fi
done
if [ $flag -eq 0 ]
  then
   return 1
else
   echo -e "Username already exists.Please enter a different username"
   echo Pre-existing username entered.Prompted to enter again | ts >> activity.log
   userup
fi
}

 #to check if username entered by user to sign in present in database :

function signin_valid
{
flag=0
num=`cat user.csv | wc -l`
existname=(`cat user.csv`)
password=(`cat password.csv`)
length=${#existname[*]}

for id in `seq 0 1 $(($length - 1))`
  do
   if [ "$name" = "${existname[$id]}" ]
   then
       respass=${password[$id]}
   return 1 #exit function as username matches entry in database
   else
   flag=`expr $flag + 1` #increament if name doesnt match entry in database
   continue
   fi
  done

if [ $flag -gt 0 ]
  then
     echo -e "Username not present!!Try again"
     echo Invalid username entered.Prompted to enter again | ts >> activity.log
     userin # ask user to follow signin procedure again as name doesnt match

fi
}

         # take username to signin :

function userin
{
unset name
echo -e "Username:"
read name
signin_valid ${name}  # to validate user based on presence in data base
}
# take password for signin :
function passin
{
echo -e "Password:"
read -s pass



if [ "$pass" = "$respass" ] #to match password with password given
                         #  at the time of signup
   then
     echo
     echo -e "Signin Successful"
     echo Signin Successful | ts >> activity.log
     echo $name signed in | ts >> activity.log
	 sleep 1
     return 1 # exit function if passwords match
else
     echo -e "Incorrect!!Try again"
     echo Invalid password entered.Prompted to enter again | ts >> activity.log
     passin #ask user to give password again as doesnt match entry in data base
fi
}


function userup
{

unset name
echo -e "Username: "
read name
if [ "$name" == "`echo $name`" ] # to check if username is alphanumeric or not
   then
      uservalid ${name} #check if username already exists (unique or not)
      echo "$name"  >> user.csv #add unique username to database
      return 1
else
      echo "Invalid input!!Try again"
      echo Invalid username entered.Prompted to enter again | ts >> activity.log
      userup #ask user to enter username again as it is not unique
             #(already exists in data base)
fi
}

         #take password to signup :

function passup
{
unset pass
echo -e "Password(should contain atleast a number and a symbol and min. 8 characters long)"
read -s pass
if [[ $pass =~ ^.*[0-9].*$ ]] && [[ $pass =~ ^.*[!@#$%^\&\*].*$ ]] && [[ ${#pass} -ge 8 ]]
          #to check if password has atleast one number,one special character and atleast 8 characters long
   then
     echo
     echo Re-enter the password
     read -s repass
     echo
         if [ "$repass" == "$pass" ]
             then
               echo "$pass" >> password.csv
                          #add password to database with respective username
               #echo >> password.csv
               echo -e "Signup Successful" #password and username meet requirements
               echo Signup successful | ts >> activity.log
               echo $name signed up | ts >> activity.log
			  
         else
 echo -e "Invalid input!!Try again (password not matching re-entered password)"
 echo Re-entered password not matching.Prompted to enter again | ts >> activity.log
    passup #ask user to enter password again as not matching re-entered password
         fi
else
     echo -e "Invalid input!!Try again (password not matching requirements)"
    passup #ask user to enter password again as not matching requirements
fi
}

         #main function or script :

function clitest
{
echo User starting script | ts >> activity.log
echo
echo -e "**************************************************************************************************************  "
echo -e "               #####                                 WELCOME                                  ##### "
echo -e "**************************************************************************************************************  "
echo
echo -e "Please select an option :"
echo
echo "            1-Signup"
echo "            2-Signin"
echo "            3-Exit"
echo
read -t 10 option
echo
if [ ! -z "$option" ] #check if option entered or not by checking size of parameter(0 or not)
   then
    echo User prompted with options | ts >> activity.log
                                  #read option and append to log with time stamp
else
    echo
    echo -e " Timeout!!   "
    echo "Script timedout" | ts >> activity.log
    sleep 1
    clear
    echo -e "Do you want to continue"
	echo "Script timed out.Propmted with option" | ts >> activity.log
	read -s op
	if [ $op == "y" ]
		then
			echo User decided to execute script again | ts >> activity.log
			bash command_line_test.sh
	else
            echo User decided to exit script | ts >> activity.log

	    clear
         echo -e " ****************************************************************************************************  "
		 echo -e "       ##########                       Thank you for trying the program             ##########        "
		 echo -e " ****************************************************************************************************   "
         sleep 1
		 clear
			exit
    fi
fi
case $option in

    1)
    echo -e "You chose to signup"
	echo
	echo User decided to signup | ts >> activity.log
    userup  #call functions related to signup
    
    passup
    ;;

    2) #signin
  
    echo -e "You chose to signin"
    echo
	echo User chose to signin | ts >> activity.log
    userin  #call functions related to signin
    
    passin

	echo -e "Would you like to take the test?"
	echo  "          1-Take test "
	echo  "          2-Exit to main Menu(Signout)     "

    echo
    read select
	echo

     if [ $select -eq 1 ] #take
         then
		   echo User decided to take test | ts >> activity.log
                          #read option and append to log with time stamp

		       
           clear
           len=`grep "^[0-9]\+\." questions_bank.txt | wc -l`
                                       #to get number of questions
           declare -a num=(`shuf -i 1-${len} -n ${len}`)
                         #to generate random numbers btw 1 and (no of questions)
           q=1  #to print question number in a series starting from 1

           for (( i=0; i<${len}; i++ ))
             do
			   unset ans
               a=${num[i]} #random question number
			   echo -n "$q." #to print question number
			   echo -e "------------------------------------------------------------------------------"
               sed -n "/^${a}\./,+4p" questions_bank.txt | cut -d "." -f2 | cut -d "|" -f 1
			   echo -e "--------------------------------------------------------------------------------"
               sed -n "/^${a}\./,+4p" questions_bank.txt | cut -d "." -f2 | cut -d "|" -f 1 > f.txt

               echo

                        # to limit user to a certain time limit to answer

               total=10  # total wait time in seconds
               count=0  # counter
               while [ ${count} -lt ${total} ]
                 do
                   tlimit=$(( $total - $count ))
                 echo -e "\n${tlimit} seconds remaining. Answer: \c"
                   read -t 1 ans
                   test ! -z  "$ans" && { break ; } #if not zero break else increment count value
                   count=$((count+1))
                 done
                     if [ ! -z "$ans" ]
                       then
						b=`grep -e "^${ans}).*$" f.txt | cut -d ")" -f 2` #to show only answer and not option
						c=`grep -e "^${ans}).*$" f.txt` #to show answer with option
                        echo -e "\nYour answer is ${b}"
                        echo -e "You answered in `expr 10 - $tlimit` seconds"
	       				echo "`sed -n "/^${a}\./p" questions_bank.txt | cut -d "|" -f1`,$c" >> h.txt

                        sleep 2
                   else
	
                    echo "`sed -n "/^${a}\./p" questions_bank.txt | cut -d "|" -f1`,e)timed out " >> h.txt
                        echo -e "\nTime out!"
	                    sleep 1
                    fi
					q=`expr $q + 1`
              clear
              done
			  cat h.txt | sort -n > q.txt #to get original sequence of question numbers
             3
              echo Test completed by the user | ts >> activity.log
			  echo
			 
              clear


		  
		   echo
           echo -e "                        ***********************     RESULT TIME     **************************                       "
           echo
          
		   sleep 1
		   clear
           mark=0
           array1=(`grep -e "^[0-9]\+\." questions_bank.txt | cut -d "|" -f2`) #right answers put in an array
           array2=(`cut -d "," q.txt -f 2 | cut -d ")" -f 1`)  #user entered answers put in  array
		   num=${#array1[@]}
		   for ((i=1;i<=num;i++))
			   do
				j=`expr $i - 1`
					if [[ ${array2[j]} == e ]]
						then
				          sed -n "/^${i}\./,+4p" questions_bank.txt | cut -d "|" -f1 > m.txt
						  sed -i "1s/$/`echo -e " status Timed Out"`/" m.txt
						  cp m.txt o.txt
				          cat o.txt | GREP_COLORS="mt=01;32" grep --colour=always -e "^" -e "${array1[j]}).*" >> right.txt
				          echo >> right.txt

				    elif [[ ${array1[j]} != ${array2[j]} ]]
					    then
			              sed -n "/^${i}\./,+4p" questions_bank.txt | cut -d "|" -f1 > m.txt
						  sed -i "1s/$/`echo -e "status wrong"`/" m.txt
						  cp m.txt o.txt
                          cat o.txt | GREP_COLORS="mt=01;31" grep --colour=always -e "^" -e "${array2[j]}).*" > r.txt
                          cat r.txt | GREP_COLORS="mt=01;32" grep --colour=always -e "^" -e "${array1[j]}).*" >> right.txt
                          echo >> right.txt

				    elif [[ ${array1[j]} == ${array2[j]} ]]
				        then
					      mark=`expr $mark + 1`
					      sed -n "/^${i}\./,+4p" questions_bank.txt | cut -d "|" -f1 > m.txt
	                      sed -i "1s/$/`echo -e "status : Right"`/" m.txt
						  cp m.txt o.txt
						  cat o.txt | GREP_COLORS="mt=01;31" grep --colour=always -e "^" -e "${array2[j]}).*" > r.txt
						  cat r.txt | GREP_COLORS="mt=01;32" grep --colour=always -e "^" -e "${array1[j]}).*" >> right.txt
			              echo >> right.txt

			        fi
                echo $name scored ${mark}/${num} | ts >> activity.log
			   done
            (
			
             echo -e "                      ***  You scored ${mark}/${num}  ***         "
			 echo
			 echo -e "Use up  and   down   arrow keys to navigate and 'q' to quit "
			 echo -e "------------------------------------------------------------------"
             cat right.txt
			 echo -e "------------------------------------------------------------------"
			 echo -e "Use up   and  down   arrow keys to navigate and 'q' to quit"
            ) | less -R

					else
						echo User decided to exit to main menu | ts >> activity.log
						echo $name signed out | ts >> activity.log
						clear
						bash command_line_test.sh
                    fi
                    ;;


                3) #exit
    
	  echo User decided to exit script | ts >> activity.log
      clear
	  echo
	  echo
	 
	  echo -e "                                  Thank you for using the script                                    "
	 
	  sleep 2
      clear
      rm f.txt h.txt q.txt r.txt right.txt o.txt m.txt
      exit
      ;;

  *)
     echo -e "Invalid input.Try again"
     clitest #call main function again
     ;;
     esac



}

clitest

while [ 1 ]
  do
    echo -e "Do you want continue ?" # user wants to execute procedure again
    echo User prompted to continue or exit | ts >> activity.log
    echo
    echo *Enter yes to continue
    echo *Enter no to exit
    echo
    read option
    if [ $option == "yes" ]
      then
      echo User decided to continue | ts >> activity.log
      clear
      clitest #call main function
    else
      echo User decided to exit | ts >> activity.log
	  rm f.txt h.txt q.txt r.txt right.txt o.txt m.txt
	  clear
      echo
      echo
      echo -e " ****************************************************************************************************** "
	  echo -e "          #########                  Thank you for using the script      ##########                          "
	  echo -e " ****************************************************************************************************** "

      sleep 1
      clear
      exit
   fi
  done
