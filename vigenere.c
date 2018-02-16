#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
int main(int argc,string argv[])
{
    int validarg=1;
    for(int i=0;i<strlen(argv[1]);i++)
    {
        if(!isalpha(argv[1][i]))
            validarg=0;
    }
    if(argc!=2 || validarg==0)
    {
        printf("Failed ! \n");
        return 1;
    }
    string text,key;
    key=argv[1];
    text=get_string("Enter Text : \n");
    int klen,tlen,i,j;
    klen=strlen(key);
    tlen=strlen(text);
    for(i=0,j=0;i<tlen;i++)
    {
        if(isalpha(text[i]))
        {
            if(isupper(text[i]))
            {
                printf("%c" ,(text[i]-'A' +toupper(key[j%klen])-'A')%26 +'A');
                j++;
            }
            else if(islower(text[i]))
            {
                printf("%c" ,(text[i]-'a' +tolower(key[j%klen])-'a')%26 +'a');
                j++;
            }
        }
        else
        {
            printf("%c",text[i]);
        }
    }
    printf("\n");

}