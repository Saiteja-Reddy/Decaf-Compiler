#include <stdio.h>
#include <math.h>

int read_integer()
{
    int a;
    scanf("%d", &a);
    return a;
}

int get_pow(int a, int b)
{
    int val = pow(a,b);
    printf("%d \n", val);
    return val;
}
