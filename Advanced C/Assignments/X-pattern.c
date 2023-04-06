#include <stdio.h>

/*

Name: N. Venkatesan
Date: 01-Jan-2023
Description: 
Sample Input:
Sample output: 

*/


int main()
{
	int i, j, num; //declaration of variables for for loop and num to get a number from the user
    printf("Enter the number: \n");
    scanf("%d", &num);
    for ( i = 1; i <= num; i++ )  //number of rows = num so iterating for num times
	{
		for ( j = 1; j <= num; j++ )  //number of columns = num, so iterating for num times here as well 
		{
			if ( i == j || (i + j) == (num + 1) )  //logic to print numbers in x format.
			{
			   printf("%d", j);
			}
	        else
			{
		        printf(" ");
		    }
	    }
        printf("\n");   //To go to the next row
    }
    return 0;
}	
