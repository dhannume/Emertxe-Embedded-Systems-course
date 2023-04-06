#include <stdio.h>

/*

Name: N. Venkatesan
Date: 20-Jan-2023
Description: 
Sample Input:
Sample output: 

*/

int toggle(int, int, int); //fn prototype
int main()
{
	int num, n, pos, result; //var declaration of number whose n bits from the given position has to be toggled.
	printf("Enter the number: ");
	scanf("%d", &num);
	printf("Enter number of bits: ");
	scanf("%d", &n);
	printf("Enter the pos: ");
	scanf("%d", &pos);
	result = toggle(num, n, pos); //fn call to invert the n bits from the pos given from the given number.
	printf("Result = %d\n", result);
	return 0;
}
int toggle(int num, int n, int pos)  //fn defn
{
	int res, get_nbits; //var declaration of res and get_nbits to get the required output and return to the var which has called this function
	get_nbits = ((1<<n)-1); //This gives number of bits that has to be toggled.(Mask)
	res = num ^ (get_nbits << (pos-n+1)); //This actually shifts the mask to the bit position and toggles the num value using xor operator
	return res;
}
