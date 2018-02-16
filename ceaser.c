#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc,string argv[])
{
    if(argc!=2)
    {
        printf("Ceaser Cipher Usage : ./ceaser k \n");
        return 1;
    }
    string k=argv[1];
    int key=atoi(k);
    if(key<=0)
    {
        printf("Enter a +ve integer \n");
        return 1;
    }
    string text=get_string("Enter Text : \n");
    int len=strlen(text);
    for(int i=0;i<len;i++)
    {
        if(isalpha(text[i]))
        {
            if(islower(text[i]))
            {
                printf("%c",(((text[i]+key)-'a')%26)+'a');
            }
            else if(isupper(text[i]))
            {
                printf("%c", (((text[i]+key)-'A')%26)+'A');
            }
        }
        else
        {
            printf("%c",text[i]);
        }
    }
    printf("\n");
}