#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // get card number
    long long card_number = get_long_long("Credit card number: ");

    // test if card number is valid

    int digit;
    long long int remaining_digits = card_number;
    int factor_ten = 0;
    int checksum = 0;

    while (remaining_digits > 0)
    {
        digit = remaining_digits % 10;

        if (factor_ten % 2 == 0) // premier, troisième, etc chiffre de la carte
        {
            checksum += digit;
        }
        else // second, quatrième chiffre de la carte
        {
            // on ajoute la somme des chiffres de digit*2, i.e unités + 1 si digit >=5
            checksum += (digit * 2) % 10;

            if (digit >= 5)
            {
                checksum += 1;
            }
        }

        // increment for next iteration
        factor_ten++;
        remaining_digits = card_number / pow(10, factor_ten);
    }

    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // define card issuer through first digits
    long long int first_two_digits;
    factor_ten = 0;

    do
    {
        first_two_digits = card_number / pow(10, factor_ten);
        factor_ten ++;
    }
    while (first_two_digits > 99);

    int card_number_length = factor_ten + 1;

    if ( (first_two_digits == 34 || first_two_digits == 37) && card_number_length == 15) // 34 or 37  & len15= AMEX
    {
        printf("AMEX\n");
    }
    else if ( (first_two_digits >= 51 && first_two_digits <= 55) && card_number_length == 16) // between 51 and 55 incl œ len 16 = Matercard
    {
        printf("MASTERCARD\n");
    }
    else if ( (first_two_digits >= 40 && first_two_digits <= 49) && (card_number_length == 13 || card_number_length == 16) ) // starting with a 4 & len 13or16= Visa
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}