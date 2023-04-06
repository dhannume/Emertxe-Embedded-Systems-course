#include <stdio.h>

/*

Name: N. Venkatesan
Date: 06-Jan-2023
Description: to print a pyramid pattern based on user input
Sample Input:
Sample output: 

*/

int main()
{
	int i,j,num;
	printf("Enter the number: ");
	scanf("%d", &num);
	for ( i = 1; i <= (num * 2)-1; i++) 
	{
		for ( j = 1;j <= num; j++ ) 		{
			if ( i == j || ((i > num) && (i+j) == (num*2))) //logic to print num value, ie 4 if num = 4
				printf("%d ", num);
			else if ( i == num )  //logic to print exact middle line of the pattern that ranges from 1 to 4 here.
				printf("%d ", j);
		    else if ( j < i && i < num ) // logic to print values for rows less than middle row, to print only j value less than i
				printf("%d ", (num - (i-j)));  // num - (i-j) gives me values to print values before i == j, i.e num value
			else if ( i > num && (i+j) < (num*2) )  //logic to print values for rows after middle row.
			    printf("%d ", ((i+j)-num));  //logic is (i+j) - num gives values to print before num value i.e 1, 2, 3, if num = 4
		}
		printf("\n");  //to go to next row after first row pattern is printed
	}
	return 0;
}
