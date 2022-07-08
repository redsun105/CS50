#include <stdio.h>
#include <cs50.h>
int main(void)
{

    long n = get_long("n= ");
    int mod1 = 0;
    int mod2 = 0;
    int sum1 = 0;
    int sum2 = 0;

    do
    {
    mod1 = n % 10;
    sum1 = sum1 + mod1;
    n= n /10;
    }
    while(n>0);

    printf("%i\n",sum1);
}



//get starting digit
    do
    {
        start = start /10;
    }
    while(start>100);

    if(start == 34 || start == 37)
    {
        printf("AMEX\n");
    }
    if(start == 51 || start == 52 || start ==53 || start ==54 || start== 55)
    {
        printf("MASTERCARD\n");
    }
    if(start > 39 && start <50)
    {
        printf("VISA\n");
    }