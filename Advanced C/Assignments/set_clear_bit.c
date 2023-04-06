#include <stdio.h>

/*

Name: N. Venkatesan
Date: 12-Jan-2023
Description: to check N th bit is set or not, If yes, clear the M th bit
Sample Input:
Sample output: 

*/

int main()
{
	int num, M, N, clr_bit;  //Storing the number in num and bit positions in M and N variables and clr_bit to store clear bit value.
	printf("Enter the number: ");
	scanf("%d", &num);
	printf("Enter 'N': ");
	scanf("%d", &N);
	printf("Enter 'M': ");
	scanf("%d", &M);
	if ( num & (1 << N) )
	{
		clr_bit = (num & (~(1 << M)));
	    printf("Updated value of num is %d\n", clr_bit);
    }
    else
    {
        printf("Updated value of num is %d\n", num);
    }
    return 0;
}
