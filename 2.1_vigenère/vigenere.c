#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    // ensure only one argument
    if (argc != 2)
    {
        printf("Error: you should use one and only one argument.\n");
        return 1;
    }

    string keyword = argv[1];

    // ensure only letter in argument
    for (int i = 0; keyword[i] != '\0'; i++)
    {
        if (!(keyword[i] > 64 && keyword[i] < 91) && !(keyword[i] > 96 && keyword[i] < 123))
        {
            printf("Error: non-alphabetical symbol in argv.\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext:  ");
    int kw_rank = 0;
    printf("ciphertext: ");


    for (int letter = 0; plaintext[letter] != '\0'; letter++)
    {

        // slide: how much to shift letter
        int slide;
        int kw_length = strlen(keyword);

        if (keyword[kw_rank] > 64 && keyword[kw_rank] < 91)
        {
            slide = keyword[kw_rank] - 65;
        }
        // lowercase letter
        else if (keyword[kw_rank] > 96 && keyword[kw_rank] < 123)
        {
            slide = keyword[kw_rank] - 97;
        }
        else
        {
            return 3;
        }


        // uppercase letter
        if (plaintext[letter] > 64 && plaintext[letter] < 91)
        {
            printf("%c", ((plaintext[letter] - 65 + slide) % 26) + 65);
            kw_rank = (kw_rank + 1) % kw_length;
        }
        // lowercase letter
        else if (plaintext[letter] > 96 && plaintext[letter] < 123)
        {
            printf("%c", ((plaintext[letter] - 97 + slide) % 26) + 97);
            kw_rank = (kw_rank + 1) % kw_length;
        }
        else
        {
            printf("%c", plaintext[letter]);
        }
    }

    printf("\n");
    return 0;
}