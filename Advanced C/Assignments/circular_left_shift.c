#include <stdio.h>

/*

Name: N. Venkatesan
Date: 25-Jan-2023 
Description: 
Sample Input:
Sample output: 

*/

int circular_left_shift(int num, int n) //function definition to do circular left shift
{
	int res; //local var declaration to return the resultant value after circular left shift
	res = (num>>(31-n+1) & ((1<<n)-1)) | num<<n; //logic to do circular left shift
	/*
	  1) First I got n bits from msb most side
	   2) Right shifted it to LSB most side.
	   3) Just did get bits of those bits.
	   4)I left shifted num value so I got n bits of 0s appended at lsb and I just did | with n bits from lsb which was lost while left shifting to get the resultant output.
	   */
	return res;
}
int main()
{
	int num, n, result;  //local var declaration to get num and n values from the user.
	printf("Enter num: ");
	scanf("%d", &num);
	printf("Enter n : ");
	scanf("%d", &n);
	result = circular_left_shift(num, n);
	printf("Result in Binary: ");
	for ( int i = 0;i < 32; i++) //To print the bits of resultant value after circular left shift.
	{
		printf("%d ", result>>(31-i) & 1);
	}
	printf("\n");
	return 0;
}
