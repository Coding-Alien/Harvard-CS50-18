#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int shrtime,nob;
    do
    {
        shrtime=get_int("Enter your shower time in minutes : \n");
    }while(shrtime<=0);
    nob=shrtime*12;
    printf("You used %i bottles of water for your shower \n ",nob);
    return 0;
}