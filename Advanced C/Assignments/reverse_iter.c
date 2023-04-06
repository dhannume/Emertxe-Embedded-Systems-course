#include <stdio.h>
#include <string.h>
/*

Name: N. Venkatesan
Date: 07-Feb-2023
Description: 
Sample Input:
Sample output: 

*/

void reverse_iterative(char *str);
int main()
{
	char str[30];	 //string declaration   
    printf("Enter any string : ");
    scanf("%[^\n]", str);	    
    reverse_iterative(str);	 //fn call to reverse the string...				    
	printf("Reversed string is %s\n", str);
}
void reverse_iterative(char *str) //fn definition to reverse the string...
{
	int i, j = 0; char temp; //var declarations
	for ( i = strlen(str)-1; i > (strlen(str)-1)/2; i--) //logic to reverse the string, loop should run half the times of string length to reverse the string...
	{
		temp = *(str+j);
		*(str+j) = *(str+i);
        *(str+i) = temp;
		j++;
	}
}
