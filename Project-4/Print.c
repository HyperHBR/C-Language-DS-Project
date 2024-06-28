// By HyperHBR--Hardiksinh Rathod 
// Date--
// Program Name--

#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int arr[9] = {0,11,0,55,0,1,0,0,0};
    for(int i=3-1;i>=0;i--)
    {
        printf("* * * * * * * * * * * * * * * * * * * * * * * * \n");
        if(i%2==0)
        {
            for(int j=0;j<3;j++)
            {
                if(arr[(i*3)+j]==55)
                {
                    printf("*  Snake (3)  * ");
                }
                else if(arr[(i*3)+j]==11)
                {
                    printf("* Ladder (4)  * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=0;j<3;j++)
            {
                if(arr[(i*3)+j] == 1)
                {
                    printf("*     ###     * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=0;j<3;j++)
            {
                if(arr[(i*3)+j] == 1)
                {
                    printf("*      #      * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=0;j<3;j++)
            {
                printf("* %d           * ",((i*3)+j+1));
            }
            printf("\n");
        }
        else
        {
            for(int j=3-1;j>=0;j--)
            {
                if(arr[(i*3)+j]==55)
                {
                    printf("*  Snake (3)  * ");
                }
                else if(arr[(i*3)+j]==11)
                {
                    printf("* Ladder (4)  * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=3-1;j>=0;j--)
            {
                if(arr[(i*3)+j] == 1)
                {
                    printf("*     ###     * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=3-1;j>=0;j--)
            {
                if(arr[(i*3)+j] == 1)
                {
                    printf("*      #      * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=3-1;j>=0;j--)
            {
                printf("* %d           * ",((i*3)+j+1));
            }
            printf("\n");
        }
    }
    printf("* * * * * * * * * * * * * * * * * * * * * * * *\n");
    return 0;
}