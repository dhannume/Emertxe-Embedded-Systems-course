#include <stdio.h>

/*

Name: N. Venkatesan
Date: 20-Jan-2023
Description: to print N bits from the LSB end of given number. N input to be taken from user.
Sample Input:
Sample output: 

*/

void print_nbits_from_LSB(int, int, int); //fn prototype to print n bits from lsb of a given number
int main()
{
	int num, n, i;  //variable declaration to store user given values number, n bits and control var used in for loop.
	printf("Enter the number: ");
	scanf("%d", &num);
	printf("Enter number of bits: ");
	scanf("%d", &n);
	if ( n > 32 )  //if user given more than size of int type, then make it to 32
		n = 32;
     print_nbits_from_LSB(num, n, i); //just function call to print just n bits from a number.
	 return 0;
}
void print_nbits_from_LSB(int num, int n, int i) //fn definition to print n bits
{
	printf("Binary form of %d: ", num);
	for ( i = 1; i <= n; i++)
	{
		printf("%d ", (num >> (n-i)) & 1);  //logic to get only the n bits from lsb side with binary value only(1 or 0).
	}
	printf("\n");
}
