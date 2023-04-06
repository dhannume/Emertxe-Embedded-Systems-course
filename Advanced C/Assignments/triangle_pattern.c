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
	int num,i,j,count=0;
	printf("Enter the number: ");
	scanf("%d", &num);
    for ( i = 1; i <= num; i++ )  //i is rows from 1 to num value
	{
		for ( j = i; j <= num; j++ )  //j is columns from i to num value for each row, here j = i init and j <= num is condn..
		{
			if ( j == i || j == num || i == 1 )   //all these condns suits to print hollow right angle triangle pattern in upside dowm way.
			{
				count++;
			    printf("%d ", count);
			 }
		     else
			 {
			     printf("  ");
			 }
		  }
      printf("\n");
	}
    return 0;
}	
