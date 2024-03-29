#include <stdio.h>

/*

Name: N. Venkatesan
Date: 26-Jan-2023
Description: to find the third largest value in an array. size of array and values in the array input to be taken from user.
Sample Input:
Sample output: 

*/

int largest(int *, int); //fn prototype to find the largest element
int my_second_largest(int *, int, int); //fn prototype to find the second largest element.
int my_third_largest(int *, int, int, int); //fn prototype to find the 3rd largest ele of an array.
int largest(int *array, int size) //fn definition to find largest ele of an array.
{
	int index_of_largest = 0, largest, third_largest; //var declarations, index_of_largest stores index position of largest element of an array and third_largest var to store the third largest element of an array.
	largest = array[0]; //initializing temp var "largest" with first index of array element.
	for ( int i = 1; i < size; i++) //iteration from first till last ele.
	{
		if ( array[i] > largest ) //comparison to find the largest
		{
			largest = array[i];
			index_of_largest = i;
		}
	}
	third_largest = my_second_largest( array, index_of_largest, size); //calling another fn which gives third largest ele of an array.
	return third_largest; //returning third largest ele to the main().
}
int my_second_largest( int *array, int index_of_largest, int size)//fn definition to find the second largest ele and sending the second largest element's index as an argument to my_third_largest().
{
	int second_largest, index_of_second_largest, third_largest; //var declaration to get second_largest ele and it's index position.
	if ( index_of_largest == 0 ) //comparison to check if the largest ele is first ele, if yes then initializing the second_largest var with second ele of array i.e array[1].
	{
		second_largest = array[1];
	    index_of_second_largest = 1;
	}
	else
	{
		second_largest = array[0];
		index_of_second_largest = 0;
	}	    
	for ( int i = 1; i < size; i++)
	{
		if ( index_of_largest != i ) //condition to skip the first largest element comparison to find the second largest.
		{
			if ( array[i] > second_largest )
			{
				second_largest = array[i];
				index_of_second_largest = i;
			}
		}
	}
	third_largest = my_third_largest(array, index_of_largest, index_of_second_largest, size); //third_largest gets the value that has been returned from my_third_largest() which is back returned to largest() which in turn returns finally to main().
	return third_largest; //returning to largest()..
}
int my_third_largest(int *array, int index_of_largest, int index_of_second_largest, int size) //fn definition to find third largest element of an array..
{
	int third_largest, i;
	if ( index_of_largest > 0 && index_of_second_largest > 1 ) //all possible condition checks to initialize third_largest var with an array element which should not be largest or second largest.
		third_largest = array[0];
	else if ( index_of_largest == 0 && index_of_second_largest == 1 )
		third_largest = array[2];
	else if ( index_of_largest == 0 && index_of_second_largest > 1 )
		third_largest = array[1];
	else if ( index_of_largest > 0 && index_of_second_largest == 1 )
		third_largest = array[0];
	else
		third_largest = array[2];
	for ( i = 0; i < size; i++ )
	{
		if ( i == index_of_largest || i == index_of_second_largest )
			continue; //to skip the second largest and largest elements comparisons.
		else
			if ( array[i] > third_largest )
			{
				third_largest = array[i];
			}
	}
	return third_largest; //This returns third_largest element to my_second_largest()..
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
	printf("Third largest element of the array is %d\n", result);
	return 0;
}
