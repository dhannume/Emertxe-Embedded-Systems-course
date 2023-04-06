#include <stdio.h>

/*

Name: N. Venkatesan
Date: 22-Feb-2023
Description: 
Sample Input:
Sample output: 

*/

#include <stdio.h>
#include <stdio_ext.h> 

char *my_strtok(char * str, const char *delim); //fn prototype of user defined strtok fn...
int main()
{
	char str[1500];	    //string declration...
    printf("Enter string1  : ");
	scanf("%499[^\n]", str);				    
	__fpurge(stdin);				 
	printf("Enter string2 : ");
	scanf("%499[^\n]", delim);
	__fpurge(stdin);							    
	char *token = my_strtok(str, delim); //First time fn call
	printf("Tokens :\n");				
	while (token) //If token != NULL then printing string...
	{
		printf("%s\n", token);
		token = my_strtok(NULL, delim); //2nd time fn call with NULL as 1st arg, which is given in same way for strtok fn...
	}
}
char *my_strtok(char *str, const char *delim) //fn definition...
{
	int j = 0; //To iterate delim string till '\0'
	static int i; //To iterate main string till '\0'..Static var bcoz to continue with next character after replacing \0 char when token found in string...
	static char *temp; //To take the base addr of main string initially and keep moving with next characters...
	int length = i; //This var actually confirms whether both prev and present char are \0, if yes then without returning any addr, moving with next char in string...
	if ( str != NULL ) //If str is not equal to NULL addr then temp takes addr of str, for first time when fn called...
	{
		temp = str;
	}
	while ( temp[i] != '\0') //Iterating with all characters from main string and checking for tokens...
	{
		j = 0;
		while ( delim[j] != '\0' ) //Iterating all tokens with each char of main string and if found equal then replacing it...
		{
			if ( delim[j] == temp[i] ) //If token found in string...
			{
				temp[i] = '\0'; //Making that char in string as \0...
				i++; //Then moving with next char...
				if ( temp[length] != '\0') //If the prev char was not \0, then returning the base addr for first and then addr after \0...
				{
					return (&temp[length]);
				}
				else
				{
					length = i; //If prev char and present char became \0, then just moving with next char...
					i--; //To compensate i++ present after inner while loop...
					break; //breaks from inner while loop
				}
			}
			j++;
		}
		i++;
	}
	if ( temp[length] == '\0' ) //If \0 has been reached in main string then returning NULL as per behaviour of strtok fn...
	{
		//i = 0;
		return NULL;
	}
	else
	{
		return (&temp[length]); //returning the addr...
	}
}
