#include <stdio.h>
#include <stdio_ext.h>
/*

Name: N. Venkatesan
Date: 
Description: 
Sample Input:
Sample output: 

*/

int main()
{
	char option, ch; //option to ask whether user wants to continue and ch to store the character...
	do
	{
	    char prev_character = ' '; //to hold the previous entered character so that if multiple spaces or tab spaces or \n given then to consider only 1 word count...
	    int wordcount = 0, charcount = 0, linecount = 0; //var initialization...
		__fpurge(stdin); //To clear the input buffer for every time the user wants to continue...
		while ( (ch = getchar()) != EOF ) //To enter the character untill EOF is given by the user...
	    {
			charcount++; //To get the character count...
		    if ( (prev_character != ' ' && prev_character != '\n' && prev_character != '\t') && (ch == 9 || ch == 32 || ch == 10 || ch == 0 )) //conditions to increment the word count...
			   wordcount++;
			prev_character = ch; //for every character entered by the user, previous character gets updated with it...
		    if ( ch == 10 ) //10 here is \n, so to increment the line count...
			   linecount++;
	    }
		if ( prev_character != '\n' && ch == EOF ) //in new line first word count has to be included, so this condition...
			wordcount += 1;
	    printf("\nCharacter count : %d\n", charcount);
	    printf("Line count : %d\n", linecount);
	    printf("Word count : %d\n", wordcount);
	    printf("Do you want to continue(y/Y) : ");
	    scanf("%c", &option);
	} while ( option == 'y' || option == 'Y' );
	return 0;
}
