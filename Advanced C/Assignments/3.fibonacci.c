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
int n, i, a = 0, b = 1, c;

printf("Enter a number: ");
scanf("%d", &n);

if (n < 0)
{
    printf("Invalid input");
    return 0;
}

printf("%d ", a);
printf("%d ", b);

c=0;

for (i = 2; c <= n; i++)
{
    c = a + b;
    a = b;
    b = c;
    printf("%d ", c);
}

return 0;
}
