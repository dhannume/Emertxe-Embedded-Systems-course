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
int num;
printf("Enter the value of 'n': ");
scanf("%d", &num);

if (num == 0)
{
    printf("0 is neither odd nor even.\n");
}
else if (num < 0)
{
    if (num % 2 == 0)
    {
        printf("%d is negative even number.\n", num);
    }
    else
    {
        printf("%d is negative odd number.\n", num);
    }
}
else
{
    if (num % 2 == 0)
    {
        printf("%d is positive even number.\n", num);
    }
    else
    {
        printf("%d is positive odd number.\n", num);
    }
}

return 0;
}

