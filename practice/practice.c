
#include <stdio.h>

int main(void)
{
    //char x[10];
    //printf("whats your name?\n");
    //scanf("%s", x);
    //printf("Hello, %s\n", x);

    //int x;
    //printf("how old are you?\n");
    //scanf("%d", &x);
    //printf("you are a %d years old person\n", x);


    for(int i = 0; i < 10; i ++){
        if(i < 5){
            printf("less than 5\n");
            return 1;
        }
    }

    printf("a\n");
    return 0;

}
