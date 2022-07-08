#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt for card number
    long n=get_long("what's your card number? ");
    long start = n;
    long length = n;
    //count card number length
    int count=0;
    do
    {
        length=length/10;
        count++;
    }
    while(length>0);

    //checke if length is valid
    if(count != 13 && count !=15 && count !=16)
    {
        printf("INVALID\n");
        return 0;
    }

    // count sum
    long x = n;
    int sum1 = 0;
    int sum2 = 0;
    int total = 0;
    int mod1 = 0;
    int mod2 = 0;
    int d1 = 0;
    int d2 = 0;
    for(int i=1; i<count+1; i++)
    {
        mod1 = x % 10;

        if(i%2 !=0 || i==1)
        {
            sum1 = sum1 + mod1;
        }

        else{
            mod2 = 2 * mod1;
            d1 = mod2 % 10;
            d2 = mod2 / 10;
            sum2 = sum2 + d1 + d2;
            }

         x = x / 10;
    }

    //check sum
     total = sum1 + sum2;
     printf("%i\n",sum1);
     printf("%i\n",sum2);
    if(total % 10 !=0)
    {
        printf("INVALID\n");
        return 0;
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
    else if(start == 51 || start == 52 || start ==53 || start ==54 || start== 55)
    {
        printf("MASTERCARD\n");
    }
    else if(start > 39 && start <50)
    {
        printf("VISA\n");
    }
    else{
        printf("INVALID\n");
    }
}