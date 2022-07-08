#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

int main (int argc, string argv[])
{
    string key = argv[1];

//check for commandline argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int length = strlen(key);

//check for alphabet
    for (int i = 0; i < length; i++)
    {
        if (isalpha(key[i]) == false)
        {
            printf("Key Must Only Contain Alphabetic Characters.\n");
            return 1;
        }
    }

//check for key length
    if (length != 26)
    {
        printf("Key Must Contain 26 Characters.\n");
        return 1;
    }

//check for repeatition
    for (int j = 0; j < length; j++)
    {
        for ( int k = 0; k < length; k++)
        {
            if (key[j] == key[k] && k != j)
            {
                printf("Key Must Not Contain Repeated Characters.\n");
                return 1;
            }
        }
    }

    string text = get_string("Plaintext: ");
    string abc = "abcdefghijklmnopqrstuvwxyz";
    string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len = strlen(text);
    char cipher[100];

//change text to ciphertext according to key
    for (int i = 0; i < len; i++)
    {
        for(int l = 0; l < 26; l++)
        {
            if(isalpha(text[i]))
            {
                if(islower(text[i]))
                {
                    if(text[i] == abc[l])
                    {
                        cipher[i] = tolower(key[l]);
                    }
                }
                if(isupper(text[i]))
                {
                    if(text[i] == ABC[l])
                    {
                        cipher[i] = toupper(key[l]);
                    }
                }
            }
            else{
                cipher[i] = text[i];
            }
        }
    }
    printf("ciphertext:%s\n",cipher);
}