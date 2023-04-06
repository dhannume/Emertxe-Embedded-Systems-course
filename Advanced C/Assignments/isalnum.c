#include <stdio.h>

/*

Name: N. Venkatesan
Date: 20-Jan-2023 
Description: 
Sample Input:
Sample output: 

*/

int my_isalnum(int ch) //function call to get whether character is alphanumeric or not.
{
	if ( (ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ) //Here first checking whether character entered is numeric(0-9), then uppercase alphabets(A-Z) and then for lowercase alphabets(a-z)..
	return 1;
	else
		return 0;
}
int main()
{
	char ch; int result; //var declaration to get character from the user and print the result using result varaible.
	printf("Enter the character: ");
	scanf("%c", &ch);
	result = my_isalnum(ch); //fn call and storing the return value of the function in result variable.
	if ( result ) //If result got 1 then entered character is alphanumeric.
		printf("The character '%c' is an alnum character.\n", ch);
	else
		printf("The character '%c' is not an alnum character.\n", ch);
    return 0;
}	
