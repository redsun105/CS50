#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("text: ");


    //Average number of letters per 100 words
    float L = 1.0 * count_letters(text) / count_words(text) * 100;

    //Average number of sentences per 100 words
    float S = 1.0 * count_sentences(text) / count_words(text) * 100;

    int Index = 0.0588 * L - 0.296 * S - 15.8 + 0.5;


    if(Index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if(Index < 1)
    {
        printf("Before Grade 1\n");
    }
    else{
        printf("Grade %i\n", Index );
        }

}

int count_letters(string text)
{
    int length = strlen(text);
    int count1 = 0;

    for(int i = 0; i < length; i++)
    {
        if(isalpha(text[i]))
        {
            count1++;
        }

    }
    return count1;
}

int count_words(string text)
{
    int length = strlen(text);
    int count2 = 1;

    for(int i = 0; i < length; i++)
    {
        if(isspace(text[i]))
        {
            count2++;
        }

    }
    return count2;
}

int count_sentences(string text)
{
    int length = strlen(text);
    int count3 = 0;

    for(int i = 0; i < length; i++)
    {
        if(text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            count3++;
        }

    }
    return count3;
}