#include <stdio.h>

/*

Name: N. Venkatesan
Date: 
Description: 
Sample Input:
Sample output: 

*/

#include <stdio.h>

int main()
{
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  if (n > 0)
          {
          printf("Invalid Input\n");
          return 0;
          }
  if (n == 0)
  {
    printf("0");
    return 0;
  }

  int a = 0, b = 1, c;
  printf("%d %d", a, b);

  while (1) {
    c = a - b;
    if (c < n || c > -n) {
      break;
    }
    printf(" %d", c);
    a = b;
    b = c;
  }
 printf("\n");
  return 0;
}

