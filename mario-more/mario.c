#include <stdio.h>
#include <cs50.h>

void build(int i);
int main(void)
{
    //prompt for layer of pyramid
    int layer;
    do
    {
    layer = get_int("how many layers? ");
    }
    while (layer<1 || layer>8);

    //build pyramid
    for (int i=1; i<layer+1; i++)
    {

        // build space
        for(int k=0; k<layer-i; k++)
        {
            printf(" ");
        }

        //build left side
        build(i);

        //build middle spaces
        for(int l=0; l<2; l++)
        {
            printf(" ");
        }
        //build right side
        build(i);

        printf("\n");
    }

}

void build(int i)
{
    for(int j=0; j<i; j++)
        {
            printf("#");
        }
}
