#include <stdio.h>

/*

Name: N. Venkatesan
Date: 01-Feb-2023 
Description: 
Sample Input:
Sample output: 

*/

#include <stdio.h>

int digit(char c) {
  return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

int main(void) {
  char c;
  printf("Enter the character: ");
  scanf("%c", &c);
  if (digit(c)) {
    printf("Entered character is an hexadecimal digit\n");
  } else {
    printf("Entered character is not an hexadecimal digit\n");
  }
  return 0;
}

