#include <stdio.h>
#include <string.h>
/*

Name: N. Venkatesan
Date: 07-Feb-2023
Description: 
Sample Input:
Sample output: 

*/

int itoa(char *numstr, char *str);  //fn prototype to get the string of integer entered by the user...
int main()
{
	int num=0;  //var declaration to store the number...
	char numstr[10];  //string to store the number present in num var...
	printf("Enter the number:");
	scanf("%d", &num);
    sprintf(numstr,"%d", num);	//Here num is getting converted to string...
	char str[strlen(numstr)+1]; //Taking another string to which stores exact number that we get from atoi fn...
    itoa(numstr, str);	//fn call...
    printf("Integer to string is %s\n", str);
}
int itoa(char *numstr, char *str) //fn definition...
{
	char *base_addr = numstr; //storing the base addr to verify with first character whether it is + or -  ...
	while( *numstr ) //iterating with a number, digit by digit...
	{
		if ( *numstr == '+' && numstr == base_addr) //If only first digit is + 
		{
			*numstr++; //just increment...
		}
		else if ( *numstr >= 48 && *numstr <= 57 ) //If only digit is between 0 to 9...
		{
			*str = *numstr;
			*str++;
			*numstr++;
		}
		else if ( *numstr == '-' && numstr == base_addr) //If only first digit is - then
		{
			*str = *numstr;
			*str++;
			*numstr++;
		}
		else
			*str = '0'; //If digit is not any of the above...
            *numstr++;
	}
	*str = '\0'; //After all copying of the characters adding \0 to the end of the string...
}
