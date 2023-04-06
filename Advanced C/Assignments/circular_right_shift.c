#include <stdio.h>

/*

Name: N. Venkatesan
Date: 25-Jan-2023
Description: 
Sample Input:
Sample output: 

*/

int circular_right_shift_nbits(int num, int n) //fn definition to do circular right shift
{
	int res; //var declaration to get the output of circular right shift
	res = num>>n & (~(((1<<n)-1)<<(31-n+1))) | (num&((1<<n)-1))<<(31-n+1); //Logic to get circular right shift
	/*
	   1) num value right shifted for n times.
	   2) I lost n lsb's and if sign 1 then 1 appended n times in msb, if +ve value then 0 will be present for n bits from msb.
	   3) Now i cleared n bits from mSB whether 1's or 0's. 
	   3) I performed | operation for above shifted value with below mentioned value.
	   4) I got n bits from LSB and right shifted it for MSB most side.
	   */
   return res; //returning the output to the function call.
}
void print_new_value_bits(int res) //fn definition to print bits of the resultant value.
{
	for ( int i = 0; i < 32; i++) //To print bits
	{
		printf("%d ", res>>(31-i) & 1); //logic to print each bits from MSB iteratively.
	}
}
int main()
{
	int num, n, result;
	printf("Enter num: ");
	scanf("%d", &num);
	printf("Enter n : ");
	scanf("%d", &n);
	result = circular_right_shift_nbits(num, n); //function call to get the output
	printf("Result : ");
	print_new_value_bits(result); //function call to print the output.
	printf("\n");
	return 0;
}
