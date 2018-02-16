#define _XOPEN_SOURCE
#include<unistd.h>
#include<crypt.h>
#include<stdio.h>
#include<cs50.h>
#include<string.h>
bool brute_force(string given_hash);
int main(int argc,string argv[])
{
    if(argc!=2)
    {
        printf("Crack Usage : ./crack hash \n");
        return 1;
    }
    if(!brute_force(argv[1]))
    {
         printf("Couldn't crack password \n");
         return 1;
    }
}
bool brute_force(string given_hash)
{
    string alpha="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int noc=26+26;
    char password[5],salt[3];
    salt[0]=given_hash[0];
    salt[1]=given_hash[1];
    salt[2]='\0';
    //Single letter passwords
    for(int i=0;i<noc;i++)
    {
        password[0]=alpha[i];
        password[1]='\0';
        string new_hash=crypt(password,salt);
        if(strcmp(new_hash,given_hash)==0)
        {
            printf("%s \n",password);
            return true;
        }
    }
    //2 letter passwords
    for(int i=0;i<noc;i++)
    {
        password[0]=alpha[i];
        for(int j=0;j<noc;j++)
        {
            password[1]=alpha[j];
            password[2]='\0';
            string new_hash=crypt(password,salt);
            if(strcmp(new_hash,given_hash)==0)
            {
                printf("%s \n",password);
                return true;
            }
        }
    }
    //3 letter passwords
    for(int i=0;i<noc;i++)
    {
        password[0]=alpha[i];
        for(int j=0;j<noc;j++)
        {
            password[1]=alpha[j];
            for(int k=0;k<noc;k++)
            {
                password[2]=alpha[k];
                password[3]='\0';
                string new_hash=crypt(password,salt);
                if(strcmp(new_hash,given_hash)==0)
                {
                    printf("%s \n",password);
                    return true;
                }
            }
        }
    }
    //4 letter passwords
    for(int i=0;i<noc;i++)
    {
        password[0]=alpha[i];
        for(int j=0;j<noc;j++)
        {
            password[1]=alpha[j];
            for(int k=0;k<noc;k++)
            {
                password[2]=alpha[k];
                for(int l=0;l<noc;l++)
                {
                    password[3]=alpha[l];
                    password[4]='\0';
                    string new_hash=crypt(password,salt);
                    if(strcmp(new_hash,given_hash)==0)
                    {
                        printf("%s \n",password);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}