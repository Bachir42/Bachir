\\Mamoudou Halidou Bachir
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

if (argc == 2)
{
string h;

int b=atoi(argv[1]);

p=get_string("plaintext: ");


printf("cyphertext: ");
for(int i=0; i<strlen(h); i++)

if(isalpha(p[i]))
{
    if(islower(h[i]))
        {
            
            printf("%c",(((h[i]- 97)+ b)%26)+ 97);
        }
    if(isupper(h[i]))
        {
            printf("%c",(((h[i]- 65)+ b)%26)+ 65);
        }
}
else
        {
            printf("%c",h[i]);
        }
    printf("\n");
    }
    return 0;
}
