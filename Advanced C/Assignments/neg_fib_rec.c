#include <stdio.h>

/*

Name: N. Venkatesan
Date: 31-Jan-2023
Description: 
Sample Input:
Sample output: 

*/


void my_negative_fibonacci(int n, int previous_term, int current_term, int next_term) //fn definition with recursion to print negative fibonacci series.
{
	if ( next_term >= n && next_term <= -n ) //logic to print upto the limit for -ve series.
	{
		printf("%d ", next_term);
		previous_term = current_term;
		current_term = next_term;
		next_term = previous_term - current_term;
		my_negative_fibonacci(n, previous_term, current_term, next_term); //recursive case and no base case needed here...
	}
}
int main()
{
	int n, previous_term = 0, current_term = 1, next_term = 0; //fn declaration and definition...
	printf("Enter a number: ");
	scanf("%d", &n);
	if ( n <= 0 ) //to take only -ve limit or 0 from the user...
	{
		my_negative_fibonacci(n, previous_term, current_term, next_term); //fn call from the main fn...
	printf("\n");
    }
    else
	{
	    printf("Invalid input\n");
	}
    return 0;
}	
