#include <stdio.h>
#include <stdlib.h>
/*

Name: N. Venkatesan
Date: 01-Mar-2023
Description: 
Sample Input:
Sample output: 

*/

void magic_square(int **, int); //fn prototype
int main()
{
	int n; //To consider n rows and n cols in a matrix...
	printf("Enter a number: ");
    scanf("%d", &n);
	int **ptr; //2nd level ptr to access dynamic rows and cols...
	if ( n % 2 != 0 ) //if entered no is even then magic matrix xan't be done, so print error, else calling fn to create magic matric..
		magic_square(ptr, n);
	else
		printf("Error : Please enter only positive odd numbers\n");
	return 0;
}
void magic_square(int **ptr, int n) //fn definition to create magic matrix...
{
	int i, j, middle_col; //var declarations, middle_col will have middle col...
	ptr = calloc(n, sizeof(int *)); //dynamic memory allocation for rows...
	for ( i = 0; i < n; i++ ) //dynamic memory allocation for cols
	{
		ptr[i] = calloc( n, sizeof(int));
	}
	middle_col = n / 2; //gives middle col index where 1 has to be entered...
	ptr[0][middle_col] = 1; //First putting 1 in first row middle col
	int col = middle_col + 1; //logic to create magic matrix
	int count = 1; //to write numbers incrementally...till n, including n
	for ( i = n-1;; i-- ) //infinite loop and logic is to going one row up and one col next for each iteration and writing count value...
	{
		if ( i == -1 ) //if row = -1 then making it lastindex
			i = n-1;
		if ( col == n ) //if col = n then making it 0
			col = 0;
		if ( ptr[i][col] == 0 ) //if no number written then writing count...
			ptr[i][col] = ++count;
		else if ( ptr[i][col] != 0 ) //if number already present then
		{
			if ( n == 5 ) //if 5 * 5 matrix then
			{
				if ( i <= middle_col ) //logic to go to required row
					i = i+2;
		        else
					i = i - 3;
			    if (col != 0) //if col = 0 then making it last col
	               col = col-1;
			    else
				   col = n-1;
			}
			else
			{
				i--; //this is for 3 * 3 matrix logic
				i = (i == -1 ? n-1 : i);
				col = 0;
			}
			while ( ptr[i][col] != 0 ) //iterating till i get ptr[i][col] == 0 then writing count into it...
			{
				col++;
			}
			ptr[i][col] = ++count;
		}
		col++;
		if ( count == (n*n) ) //if count reached n*n then breaking from infinite for loop
			break;
	}
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			printf("%d\t", ptr[i][j]); //printing Both dynamic 2d array which is a magic matrix now...
		}
		printf("\n");
	}
	for ( i = 0; i < n; i++ ) //freeing dynamic memory allocation after it is no needed...
	{
		free(ptr[i]);
	}
}
