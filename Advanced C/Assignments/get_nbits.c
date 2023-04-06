#include <stdio.h>

/*

Name: N. Venkatesan
Date: 20-Jan-2023
Description: To get 'n' bits of a given number
Sample Input:
Sample output: 

*/

int get_nbits( int number, int number_of_bits)  //function to get the value of n bits mentioned by the user and number and number of bits here is formal arguments.
{
	int result, mask; //var declaration
	mask = ((1 << number_of_bits)-1);  //mask to obtain just the number of bits given by the user.
	result = number & mask;  //number & mask gives the result
	return result;
}
int main()
{
	int number, number_of_bits, result;  //var declaration to get number from user, number of bits from user.
	printf("Enter the number: ");
	scanf("%d", &number);
	printf("Enter number of bits: ");
	scanf("%d", &number_of_bits);
    result = get_nbits( number, number_of_bits );  //the result from function is stored in result variable.
	printf("Result = %d\n", result);
	return 0;
}
