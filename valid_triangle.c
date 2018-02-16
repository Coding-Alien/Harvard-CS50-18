#include<stdio.h>
#include<cs50.h>
int valid_triangle(float a,float b,float c);
int main(void)
{
    float x,y,z;
    int result;
    printf("Enter the sides : \n");
    x=get_float();
    y=get_float();
    z=get_float();
    result=valid_triangle(x,y,z);
    if(result==0)
    {
        printf("Invalid triangle \n");
    }
    else
    {
        printf("Valid triangle \n");
    }

}
int valid_triangle(float a,float b,float c)
{
    if(a<=0 || b<=0 || c<=0)
        return 0;
    if(a+b<c || b+c<a || c+a<b)
        return 0;
    return 1;
}