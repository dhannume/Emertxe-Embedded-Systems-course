#include <stdio.h>

/*

Name: N. Venkatesan
Date: 07-Feb-2023
Description:  to replace each string of one or more blanks by a single blank
Sample Input:
Sample output: 

*/

void replace_blank(char *str1);  //fn call
int main()
{
	char str[150];  //string declaration...
	printf("Enter the string with more spaces in between two words\n");
    scanf("%[^\n]", str);			 
	replace_blank(str);  //fn call...
    printf("%s\n", str);				    
}
void replace_blank(char *str)  //fn definition	
{
	int i=0,j; //control var declaration to point the addresses of the string... 
	while(str[i+1]!='\0')	//Until the next character is equal to \0 keep on iterating...
	{
		if(str[i]=='\t')
		{
			str[i]=' ';			//if there is ever a TAB found then replace it with ' '...
		}		
		if((str[i]==' ') && (str[i+1]==' ') || (str[i] == ' ') && (str[i+1]== '\t')) //certain position we encounter ' ' and even next element is ' '
		{
			j=i;  //i is used for traversing string so we use another variable j
			while(str[j]!='\0')	//now j will start performing the replacement  till the end
			{
				str[j]=str[j+1];
				j++;   
			}
			i--; //Bcoz after all replacement done again going back to the address from where the replacement started...
		}
		i++;  //Then normally moving to the next character...
	}
}
