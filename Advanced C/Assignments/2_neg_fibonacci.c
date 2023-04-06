#include <stdio.h>
#include <math.h>
/*

Name: N. Venkatesan
Date: 
Description: 
Sample Input:
Sample output: 

*/

#include <stdio.h>
#include <math.h>
int main(void) {
  int num, i, t1 = 0, t2 = 1, next;

  printf("Enter a number: ");
  scanf("%d", &num);

  // Check if the input is negative
  if (num < 0) {
    printf("0 1 ");
    for (i = 2; i < num ; i++) {
      next = t1 - t2;
      t1 = t2;
      t2 = next;
      printf("%d ", next);
    }
  } else {
    printf("Invalid input\n");
  }

  return 0;
}

