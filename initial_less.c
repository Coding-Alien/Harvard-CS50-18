#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
    string name;
    char initial[5];
    int counter=0;;
    name=get_string("Enter Name : \n");
    initial[0]=toupper(name[0]);
    counter++;
    for(int i=1;i<strlen(name);i++)
    {
        if(name[i]==' ')
        {
            initial[counter]=toupper(name[i+1]);
            counter++;
        }
    }
    initial[counter]='\0';
    puts(initial);
}