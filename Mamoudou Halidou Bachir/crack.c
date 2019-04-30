#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: crack <hash>\n");
        return 1;
    }
    int letters_count = 53;
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string hash = argv[1];
    char salt[3];
    memcpy(salt, hash, 2);
    salt[2] = '\0';

    char key_computer[6] = "\0\0\0\0\0\0";

    for (int fifth = 0; fifth < letters_count; fifth++)
    {
        for (int fourth = 0; fourth < letters_count; fourth++)
        {
            for (int third = 0; third < letters_count; third++)
            {
                for (int second = 0; second < letters_count; second++)
                {
                    for (int first = 1; first < letters_count; first++)
                    {
                        key_computer[0] = letters[first];
                        key_computer[1] = letters[second];
                        key_computer[2] = letters[third];
                        key_computer[3] = letters[fourth];
                        key_computer[4] = letters[fifth];

                        if(strcmp(crypt(key_computer, salt), hash) == 0)
                        {
                            printf("%s\n",key_computer);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    printf("Error");
    return 2;
}