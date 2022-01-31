//readability
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int main(void)
{
    int x = 0;
    int y = 1;
    int j = 0;


    string input = get_string("Text: ");
    //stringlength
    int k = strlen(input);
    for (int i = 0; i < k; i++)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            x++;
        }
        if (input[i] == ' ')
        {
            y++;
        }
        //if character value is a period, exclamation mark, or question mark
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            j++;
        }
    }


    float L = (float) x / (float) y * 100;
    float S = (float) j / (float) y * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);

    printf("Grade %i\n", grade);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
}