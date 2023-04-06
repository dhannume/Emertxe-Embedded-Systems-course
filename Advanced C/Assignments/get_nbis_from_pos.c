#include <stdio.h>

/*

Name: N. Venkatesan
Date: 25-Jan-2023
Description: to get N bits from given position of a given number
Sample Input:
Sample output: 

*/

int fetch_nbits_from_pos(int number, int n, int pos) //fn defn to get n bits from the given position of a number
{
	int result, fetch; //var declaration to get n bits from given pos and store it in result var.
    fetch = (number >> (pos-n+1)); //to move n bits from the pos to lsb
    result = (fetch & ((1 << n)-1)); //getting the n bits which is now from lsb position.
    return result;
}	
int main()
{
	int number, n, pos, result; //var declarations to store number, position, number of bits and result
	printf("Enter the number: ");
	scanf("%d", &number);
	printf("Enter number of bits: ");
	scanf("%d", &n);
	printf("Enter the pos: ");
	scanf("%d", &pos);
	result = fetch_nbits_from_pos(number, n, pos); //fn calling
	printf("Result = %d\n", result);
	return 0;
}
