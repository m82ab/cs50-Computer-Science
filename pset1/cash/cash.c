//cash

#include <cs50.h>
#include <math.h>
#include <stdio.h>

float askPositiveFloat(void)
{
    // Ask user for double
    float positiveFloat;

    bool negative = true;

    while (negative)
    {

        positiveFloat = get_float("Change owed: ");

        // Check for negative
        if (positiveFloat > 0)
        {

            negative = false;
        }
    }

    return positiveFloat;
}


int j()
{

    int y = round(askPositiveFloat() * 100);

    int n = 0;

    int remainder;

    int x;

    int e = 25;
    int i = 10;
    int a = 5;
    int k = 1;




    if (y >= e)
    {

        remainder = y % e;

        x = y - remainder;

        n = n + (x / e);

        y = remainder;
    }
    // For the next coins we can safely check for them and use the same formula in sequence until the end of the function
    if (y >= i)
    {
        remainder = y % i;
        x = y - remainder;
        n = n + (x / i);
        y = remainder;
    }
    if (y >= a)
    {
        remainder = y % a;
        x = y - remainder;
        n = n + (x / a);
        y = remainder;
    }
    if (y >= k)
    {
        remainder = y % k;
        x = y - remainder;
        n = n + (x / k);
        y = remainder;
    }
    // as promised we return an integer of n
    return n;

}

int main(void)
{
    // we can use the printf function and call j() within the function itself
    printf("%i\n", j());
}