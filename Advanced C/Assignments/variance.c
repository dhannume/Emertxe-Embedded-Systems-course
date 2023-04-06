#include <stdio.h>
#include <stdlib.h>
/*

Name: N. Venkatesan
Date: 23-Feb-2023
Description: 
Sample Input:
Sample output: 

*/

float variance(int *, int); //fn prototype to find varaince...
int main()
{
	    int size, i; //var declarations
		float var;  //var variable to find variance...
		printf("Enter the no.of elements : ");
		scanf("%d", &size);
		int *ptr = malloc(size * sizeof(int)); //dynamic memory allocation for array and starting addr is stored in ptr var...
		printf("Enter the %d elements:\n", size);
		for ( i = 0; i < size; i++ ) //reading array elements dynamically allocated...
		{
			printf("[%d] -> ", i);
			scanf("%d", &ptr[i]);
		}
		var = variance( ptr, size );  //fn call to find the variance...
		printf("Variance is %f\n", var);
		return 0;
}
float variance ( int *ptr, int size )  //fn definition to find variance...
{
	int sum = 0, D, Dsqre, sum_Dsqre = 0, i; //Where D is (input - Mean) , var declarations...
	float mean, variance;   //var declarations to find mean and variance...
	for ( i = 0; i < size; i++ )
	{
		sum += ptr[i];  //Just finding sum of array elements
	}
	mean = (float) sum / size;  //finding mean...
	for ( i = 0; i < size; i++ ) //To find square of D...and it's sum
	{
		D = ptr[i] - mean; 
		Dsqre = D*D;
		sum_Dsqre += Dsqre;
	}
    variance = (float) sum_Dsqre / size;  //formula to find the variance...
    return variance;
}	
