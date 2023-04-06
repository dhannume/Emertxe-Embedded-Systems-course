#include <stdio.h>

/*

Name: N. Venkatesan
Date: 25-Jan-2023
Description: 
Sample Input:
Sample output: 

*/

#include <stdio.h>
#include <math.h>

#define LIMIT 200000

int main()
{
    int num, i, j;
    int numArray[LIMIT];
    char option;
    
    do
    {
		num = 0;
        numArray[0] = 0;
        numArray[1] = 0;
    
        /* Read a number num from user. */
        printf("Enter a number: ");
        scanf("%d", &num);
    
        /* Error Check */
        if (num < 1)
        {
            printf("Please enter a positive number which is > 1\n");
            return 1;
        }
    
        /* Arrange the numbers from 2 to num in sequential way */
        for ( i = 2; i <= num ; i++ )
        {
            numArray[i] = i;
        }
    
        /* Remove multiples of i to get prime numbers */
        for ( i = 2; i <= num; i++)
        {
            for ( j = i; j <= num; j++ )
            {
                /* mark the multiples as 0 in numArray */
                numArray[(i*j)] = 0;
            }
        }
    
        /* To print prime Numbers */
        printf("The primes less than or equal to %d are : ", num);
  
        for ( i = 2; i <= num ; i++ )
        {
            /* all non-zero values in numArray are prime */
            if (numArray[i] != 0)
            {
                printf("%d ", numArray[i]);
            }
        }
        printf("\n");
       
  }while(0);
return 1;
}
