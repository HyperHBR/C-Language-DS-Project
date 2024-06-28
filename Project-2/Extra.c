// By HyperHBR--Hardiksinh Rathod 
// Date--
// Program Name--

#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    for(int i=0;i<3;i++)
    {
        for(int l=i;l<2;l++)
        {   
            printf(" ");
        }
        for(int k=0;k<i+1;k++)
        {   
            printf("00");
        }
        printf("\n");
    }
    for(int d=0;d<3;d++)
    {
        printf("------");
        printf("\t");
    }
    return 0;
}