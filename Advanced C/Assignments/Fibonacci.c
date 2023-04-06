#include <stdio.h>

/*

Name: N. Venkatesan
Date: 31-Jan-2023
Description: to print the Fibonacci series using recursion
Sample Input:
Sample output: 

*/

void my_fibonacci(int next, int n, int a, int b)  //RECURSIVE fn to print fibonacci series
{
	if ( next <= n ) //iterative case to print fib series
	{
		printf("%d ", next);
		a = b;
		b = next;
		next = a + b;
		my_fibonacci( next, n, a, b); //here fn is calling itself with updated values for each value of next in the series.
	} //There is no base case(else statement) as nothing to do in else part.
}	
int main()
{
	int n, next = 0, a = 0, b = 1; //var declarations and definitions
	printf("Enter a number: ");
	scanf("%d", &n);
	if ( n >= 0 ) //To print only +ve fibonacci series.
	{
		my_fibonacci( next, n, a, b); //first fn call
	    printf("\n");
	}
	else
		printf("Invalid input\n");
    return 0;
}
