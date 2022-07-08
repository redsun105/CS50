#include <stdio.h>
#include <cs50.h>
int main(void)
{
    long n= get_long("n= ");
    int count=0;
    do{
        n /= 10;
        count++;
    }
    while(n>0);
    printf("%d\n",count);
}