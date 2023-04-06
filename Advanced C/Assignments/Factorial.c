#include <stdio.h>

/*

Name: N. Venkatesan
Date: 26-Jan-2023
Description:  to find the factorial using recursion method
Sample Input:
Sample output: 

*/

int my_factorial_num(int N)  //fn definition to get factorial of a number...
{
	int fact = N; //with each recursive call N updated value is given to fact var...
	if ( N > 1 ) 
	{
		N--;
		return fact * my_factorial_num( N );
	}
	else
	{
		return 1;
	}
}
int main()
{
	static int N; //variable declaration to get N value from the user whose factorial has to be found... 
	int result; //to store the factorial of a number in a var...
	printf("Enter the value of N : ");
	scanf("%d", &N);
	if ( N >= 0 ) //If given N value is less than 0 then to print error message...
	{
	     result = my_factorial_num( N ); //once fn call with N value
	     printf("Factorial of the given number is %d\n", result);
	}
    else
	{
	    printf("Invalid Input\n");
	}
    return 0;
}
