#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do

    {
        // prompt for atart size

        n = get_int("start size: ");
    }
    while (n < 9);

//prompt for and size

    int a, i;
    do
    {
        a = get_int("End Size: ");
    }
    while (a < n);
    for (i = 0; n < a; i++)
    {
        n = n + (n / 3) - (n / 4);
    }

// prints years

    printf("Years: %i", i);
    printf("\n");

}