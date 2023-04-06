#include <stdio.h>

/*

Name: N. Venkatesan
Date: 25-Jan-2023
Description: 
Sample Input:
Sample output: 

*/

int my_islower(int ch) //Fn definition to check whether entered character is lower case alphabet or not.
{
	if ( ch >= 97 && ch <= 122 ) //ascii value of lower case characters range from 97 to 122.
	   return 1;
    else
	    return 0;
}	
int main()
{
	char ch; int result; //local var declaration to store the character from user and to give the result whether it is lower case alphabet or not.
	printf("Enter the character: ");
	scanf("%c", &ch);
    result = my_islower(ch); //fn call whose return value is stored in result variable.
	if ( result ) //If result got 1 then lower case char given
		printf("Entered character is lower case alphabet\n");
	else
		printf("Entered character is not lower case alphabet\n");
	return 0;
}
