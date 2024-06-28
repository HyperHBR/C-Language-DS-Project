// By HyperHBR--Hardiksinh Rathod 
// Date--
// Program Name--

#include <stdio.h>
#include <math.h>
#include <string.h>

void printDisk(int location_of_disk,int size_of_disk)
{
    for(int j=1;j<=5;j++)
    {
        if(j!=location_of_disk)
        {
            for(int k=0;k<1;k++)
            {
                printf("\t[]");
            }
        }
        else
        {
            for(int l=0;l<9-size_of_disk;l++)
            {
                printf(" ");
            }
            for(int i=0;i<size_of_disk;i++)
            {
                printf("__");
            }
        }
        printf("\n");
    }
}

int main()
{
    int location_of_disk=5;
    int disk_size=5;

    printDisk(location_of_disk,disk_size);

    for(int i=0;i<1;i++)
    {
        printf("------------------");
        printf("\t");
    }

    printf("\n");
    return 0;
}