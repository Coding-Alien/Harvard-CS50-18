#include<stdio.h>
#include<cs50.h>
int main(void)
{
    unsigned long long ccn,cardnum,CCN;
    int len=0,sum=0,digit;
    do
    {
        printf("Enter your ccn : \n");
        ccn=get_long_long();
    }while(ccn==0);
    cardnum=ccn;
    CCN=ccn;
    while(ccn>0)
    {
        ccn/=10;
        len++;
    }
    for(int i=0;i<len;i++,CCN/=10)
    {
        if(i%2==0)
        {
            sum+=CCN%10;
        }
        else
        {
            digit=(2*(CCN%10));
            sum+=((digit/10)+(digit%10));
        }
    }
    long long i=cardnum;
    if(sum%10==0)
    {
         if ( (i >= 340000000000000 && i < 350000000000000) || (i >= 370000000000000 && i < 380000000000000) )
            printf("AMERICAN EXPRESS\n");
        else if ( i >= 5100000000000000 && i < 5600000000000000 )
            printf("MASTERCARD\n");
        else if ( (i >= 4000000000000 && i < 5000000000000) || (i >= 4000000000000000 && i < 5000000000000000) )
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
    {
        printf("Your card is INVALID \n");
    }


}