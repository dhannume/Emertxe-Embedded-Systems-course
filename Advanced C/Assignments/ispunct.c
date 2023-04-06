#include <stdio.h>

/*

Name: N. Venkatesan
Date: 25-Jan-2023
Description: to check if entered input is a punctuation
Sample Input:
Sample output: 

*/

int my_ispunct(char ch) //function call to get whether character is punctuation character or not.
{
	if ( (ch >= 33 && ch <= 47) || (ch >=58 && ch <= 64) || (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126) ) //All punctuation characters are included in conditions excluding non printable characters and alphanumeric characters.
			return 1;
	else
		return 0;
}
int main()
{
	char ch; int result; //var declaration to get character from the user and print the result using result varaible.
	printf("Enter the character: ");
	scanf("%c", &ch);
	result = my_ispunct(ch); //fn call and storing the return value of the function in result variable.
	if ( result ) //If result got 1 then entered character is alphanumeric.
		printf("Entered character is punctuation character\n");
	else
		printf("Entered character is not punctuation character\n");
    return 0;
}
