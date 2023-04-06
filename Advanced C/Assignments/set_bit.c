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
    int num, n, m;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter 'N': ");
    scanf("%d", &n);
    printf("Enter 'M': ");
    scanf("%d", &m);
    if((num >> (n-1)) & 1)
    {
        num = num & ~(1 << (m-1));
        printf("Updated value of num is %d\n", num);
    }
    else
    {
        printf("Nth bit is not set\n");
    }
    return 0;
}

