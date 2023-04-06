#include <stdio.h>

/*

Name: N. Venkatesan
Date: 20-Jan-2023
Description: to replace 'n' bits of a given number
Sample Input:
Sample output: 

*/

int replace_nbits( int, int, int);  //function prototype
int replace_nbits(int number, int n_bits, int value)  //fn definition to replace n bits from the given number
{
	int nbits, result;  //var declaration to get n bits from value and result var to return result value
	nbits = (value & (1 << n_bits)-1); //to get n bits from the value
	number = number & (~((1 << n_bits)-1)); //to clear n bits from the number
	result = nbits | number;  //To replace n bits of number with n bits of value
	return result; //returning the output
}
int main()
{
    int number, n_bits, value, result; //variable declarations to store number whose n bits has to be replaced, n_bits var to store number of bits to be replaced, value to get n bits from lsb of value and to replace it in number and resulting value storing it in result variable.
	printf("Enter the number: ");
	scanf("%d", &number);
	printf("Enter number of bits: ");
	scanf("%d", &n_bits);
	printf("Enter the value: ");
	scanf("%d", &value);
    result = replace_nbits(number, n_bits, value); //calling the function
	printf("Result = %d\n", result);
	return 0;
}
