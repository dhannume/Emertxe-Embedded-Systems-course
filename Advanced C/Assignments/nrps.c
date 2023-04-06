#include <stdio.h>

/*

Name: N. Venkatesan
Date: 22-Feb-2023
Description: 
Sample Input:
Sample output: 

*/

void nrps(char *, int, int); //fn prototype to print NRPS...
int main()
{
	int c, n, i = 0, j; //var declarations...
	printf("Enter the number characters C : ");
	scanf("%d", &c);
	printf("Enter the Length of the string N : ");
	scanf("%d", &n);
	printf("Enter %d distinct characters : ", c);
    char str[c]; //array of characters declaration...
	while ( i < c ) //to read the characters entered by the user...
	{
		__fpurge(stdin);
		scanf("%s", &str[i]);
		i++;
	}
	int flag = 0; //To check whether unique characters are entered or not...
	for ( i = 0; i < c-1; i++ )
	{
		for ( j = i+1; j < c; j++ )
		{
			if ( str[i] == str[j] )
		    {
			    flag = 1;
			    break;
			}
		}
	}
	if ( flag != 1) //If unique characters entered then calling nrps fn...
	{
		nrps( str, n, c);
	}
	else
	{
		printf("Error : Enter distinct characters\n");
	}
	return 0;
}
void nrps ( char *str, int n, int c) //fn definition...
{
	printf("Possible NRPS is "); 
	int i,j,k = 0; //var declarations...
	while ( k < n ) // printing N characters as nrps...
	{
		j = 0;
		while ( j < c && k < n ) //all characters printing 1 by 1 till end..
		{
			putchar(str[j]);
		    k++;
			j++;
		}
		j = c-1;
	    while ( j >= 0 && k < n ) //Then printing in reverse order...
		{
			putchar(str[j]);
		    k++;
			j--;
		}
	} //Next if still k < n then repeating the process...
	printf("\n");
}
