//caesar
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // Counts the number of arguements in the command line
    if (argc == 2)
    {
        const int KEY = atoi(argv[1]);
        bool j = true;
        int g = strlen(argv[1]);
        for (int x = 0; x < g; x++)
        {
            if (isdigit(argv[1][x]) == false)
            {
                j = false;
                x = g;
            }
        }

        if (j)
        {
            string plain = get_string("plaintext: ");
            int y = strlen(plain);
            for (int x = 0; x < y; x++)
            {
                if (isupper(plain[x]))
                {
                    if (plain[x] + KEY >  'Z')
                    {
                        int i = (plain[x] + KEY) - 'Z';
                        if (i > 'Z' - 'A')
                        {
                            while (i >= ('Z' - 'A'))
                            {
                                i = i - ('Z' - 'A');
                            }
                            if (plain[x] + i > 'Z')
                            {
                                i = plain[x] + i - 'Z';
                                plain[x] = 'A' + i - 1;
                            }
                            else
                            {
                                plain[x] = 'a' + i - 1;
                            }
                        }
                        else
                        {
                            plain[x] = 'A' + i - 1;
                        }
                    }
                    else if (plain[x] + KEY <= 'Z')
                    {
                        plain[x] = plain[x] + KEY;
                    }
                }
                if (islower(plain[x]))
                {
                    if (plain[x] + KEY >  'z')
                    {
                        // Takes the value of our selected letter and adds total steps then subtracts 'z' to take it down a whole rotation of the wheel
                        int i = (plain[x] + KEY) - ('z');
                        if (i >= 'z' - 'a')
                        {
                            while (i >= ('z' - 'a'))
                            {
                                i = i - (26);
                            }
                            if (plain[x] + i > 'z')
                            {
                                i = plain[x] + i - 'z';
                                plain[x] = 'a' + i - 1;
                            }
                            else
                            {
                                plain[x] = 'a' + i - 1;
                            }
                        }
                        else
                        {
                            plain[x] = 'a' + i - 1;
                        }
                    }
                    else if (plain[x] + KEY <= 'z')
                    {
                        plain[x] = plain[x] + KEY;
                    }
                }
            }
            printf("ciphertext: %s\n", plain);
        }
        // If we detected an unusable key we ask for a proper key
        else
        {
            printf("Usage: ./caesar key\n");
            printf("1");
            return (1);
        }
    }
    // If too many arguements were entered then we ask for a proper key
    else if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        printf("1");
        return (1);
    }

}