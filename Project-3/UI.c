// By HyperHBR--Hardiksinh Rathod 
// Date--
// Program Name--

#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    for(int i=0;i<20;i++)
    {
        if(i<15 && i>10)
        printf("*                                       $$$$$$$$                                          *\n");
        else if(i>3 && i<8)
        printf("*              $$$$$$$$                                            $$$$$$$$               *\n");
        else
        printf("*                                                                                         *\n");
    }
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    return 0;
}