#include <stdio.h>

/*

Name: N. Venkatesan
Date: 26-Jan-2023
Description: to read the size and elements from an array from the user and determining the second largest entity of the array
Sample Input:
Sample output: 

*/


int largest(int *, int); //fn prototype to find the largest element
int my_second_largest(int *, int, int); //fn prototype to find the second largest element.
int largest(int *array, int size) //fn definition to find largest ele of an array.
{
	int index_of_largest = 0, largest, second_largest; //var declarations
	largest = array[0]; //initializing temp var "largest" with first index of array element.
	for ( int i = 1; i < size; i++) //iteration from first till last ele.
	{
		if ( array[i] > largest ) //comparison to find the largest
		{
			largest = array[i];
			index_of_largest = i;
		}
	}
	second_largest = my_second_largest( array, index_of_largest, size); //calling another fn which gives second largest ele of an array.
	return second_largest; //returning second largest ele to the main().
}
int my_second_largest( int *array, int index_of_largest, int size)//fn definition to find the second largest ele.
{
	int second_largest; //var declaration..
	if ( index_of_largest == 0 ) //comparison to check if the largest ele is first ele, if yes then initializing the second_largest var with second ele of array i.e array[1].
		second_largest = array[1];
	else
		second_largest = array[0];
	for ( int i = 1; i < size; i++)
	{
		if ( index_of_largest != i ) //condition to skip the first largest element comparison to find the second largest.
		{
			if ( array[i] > second_largest )
			{
				second_largest = array[i];
			}
		}
	}
	return second_largest;
}
int main()
{
	int size;  //var declaration.
	printf("Enter the size of the Array : ");
	scanf("%d", &size);
	int array[size];
	printf("Enter the elements into the array: ");
	for (int i = 0; i < size; i++)  //reading array elements.
	{
		scanf("%d", &array[i]);
	}
	int result = largest(array, size); //calling function to get the second largest ele of an array.
	printf("Second largest element of the array is %d\n", result);
	return 0;
}
