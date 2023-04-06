#include <stdio.h>

/*

Name: N. Venkatesan
Date: 07-Feb-2023
Description: to implement a getword function
Sample Input:
Sample output: 

*/

int getword(char *str); //fn prototype to get the length of the first word in the string...
int main()
{
	int len = 0; //var initialization to hold the length of the string...
    char str[100]; //str string to take the string input from the user...
	printf("Enter the string : ");
    scanf(" %[^\n]", str);
	len = getword(str); //fn call 
	printf("You entered %s and the length is %d\n", str, len);
}
int getword(char *str) //fn definition to get the 1st string length...
{
	int length = 0;
	while ( *str != ' ' && *str != '\0') //condition to stop incrementing the length count if it is null char or space char...
	{
		*str++;
        length++;
	}
	if (*str == ' ') //while printing the string in the main fn i have to just print the first string, so this statement...
		*str = '\0';
	return length;
}
