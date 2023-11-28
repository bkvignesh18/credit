#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

long credit_number(void);
bool valid(long num);
char *card(long num);

int main(void)
{
    long num = credit_number();
    if (valid(num))
    {
        char card_name[20];
        strcpy(card_name, card(num));
        printf("%s\n", card_name);
    }

    else
    {
        printf("INVALID\n");
    }
}

long credit_number(void)
{
    long credit_num = get_long("Number: ");
    return credit_num;
}

bool valid(long num)
{
    int x = floor(log10(num)) + 1;
    int sum_value_1 = 0;
    int sum_value_2 = 0;

    for (int i = 1; i < x; i += 2)
    {
        long digits = ((num / (long) pow(10, i)) % 10) * 2;

        if (digits > 9)
        {
            sum_value_1 += (digits % 10) + ((digits / 10) % 10);
        }

        else
        {
            sum_value_1 += digits;
        }
    }

    for (int i = 0; i < x; i += 2)
    {
        long digits = (num / (long) pow(10, i)) % 10;
        sum_value_2 += digits;
    }

    if ((sum_value_1 + sum_value_2) % 10 == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

char *card(long num)
{
    if (((num / (long) pow(10, 13)) % 10) == 7 && ((num / (long) pow(10, 14)) % 10) == 3)
    {
        return "AMEX";
    }

    else if (((num / (long) pow(10, 15)) % 10) == 5 && ((num / (long) pow(10, 14)) % 10) <= 5)
    {
        return "MASTERCARD";
    }

    else if (((num / (long) pow(10, 15)) % 10) == 4 || ((num / (long) pow(10, 12)) % 10) == 4)
    {
        return "VISA";
    }

    else
    {
        return "INVALID";
    }
}
