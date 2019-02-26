\\ Mamoudou Halidou Bachir
#include <stdio.h>
#include <cs50.h>

int main(void){

int sum=0;
long long cc;

do
    {
        cc=get_long_long("Credit Card Number: ");
    }
while(cc<0);

//verifiy the lentgh
int count=0;
//count the number of digit
long long number=cc;
while(number>0)
{
    number=number/10;
    count++;
}
//credit card has between 13-16 depending on the type.
if(count!=13 && count!=15 && count!=16)
{
    printf("INVALID card number\n");
}
//credit card digit initialize
//starting with the last number

int digit[count];
for (int i=0; i<count; i++)
    {
        digit[i]=cc%10;
        cc=cc/10;
    }
//take the other digits

int odigit[count];
for (int i=0;i<count;i++)
    {
        odigit[i]=digit[i];
    }

//multply per 2
for (int i=1; i<count; i+=2)
    {
        digit[i]=digit[i]*2;
    }

//cheksum
//Calcul all the digits
for (int i=0;i<count; i++)
    {
        sum=sum+digit[i]%10+digit[i]/10%10;
    }
//Verify if the second num is=0
if (sum%10==0)
{
// check the type of the card
// VISA
if(count==13 && digit[12]==4 && sum%10==0)
    {
        printf("VALID VISA\n");
    }

if(count==16 && odigit[15]==4 && sum%10==0)
{
        printf("VALID VISA\n");
}

//AMEX
if(count==15 && odigit[14]==3 && sum%10==0 && (odigit[13]==4 || odigit[13]==7))
    {
        printf("VALID AMEX\n");
    }
//MASTERCARD
if(count==16 && odigit[15]==5 && (odigit[14]==1 || odigit[14]==2 || odigit[14]==3 || odigit[14]==4 || odigit[14]==5) && sum%10==0)
    {
        printf("VALID MASTERCARD\n");
    }
}
//if cheksum not verified=INVALID
else
    {
        printf("INVALID\n");
    }
}
