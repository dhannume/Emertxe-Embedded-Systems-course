#include <stdio.h>

/*

Name: N. Venkatesan
Date: 26-Jan-2023 
Description: 
Sample Input:
Sample output: 

*/

void fun(int *arr1, int size, int *arr2);  //fn prototype to remove the duplicate elements in the array...
int main()
{	
	int size, new_size, i; //var declarations
	printf("Enter the size: ");
	scanf("%d", &size);
	int arr1[size];
	int arr2[size];
	printf("Enter elements into the array: ");
	for ( i = 0; i < size; i++ )
	{
		scanf("%d", &arr1[i]);
	}
	fun(arr1, size, arr2);  //fn call...
	printf("After removing duplicates: ");
	for ( i = 0; i < size; i++)
	{
		if ( arr2[i] != 0 )  //if array elements are non-zero then printing them...
			printf("%d ", arr2[i]);
	}
	printf("\n");
}
void fun(int *arr1, int size, int *arr2)  //fn definition
{
	int i, j,first_ele, index;  //var declarations
	for ( i = 0; i < size-1; i++ )
	{
	    first_ele = arr1[i];
		index = i;
		for ( j = index+1; j < size; j++ )
		{
			if ( first_ele == arr1[j] )  //if duplicates found then making the duplicate element 0...
				arr1[j] = 0;
		}
	}
	for ( i = 0; i < size; i++ )
	{
			arr2[i] = arr1[i];  //just copying the elements from 1 array to other...Here arr1 and arr2 are pointers...
	}
}
