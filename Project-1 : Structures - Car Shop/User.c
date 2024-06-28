#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct User
{
    char *User_Name;
    int  *Mobile_Number;
    char *Email;
    char *Address;
};

void Get_User_Details();

int main()
{
    Get_User_Details();
    return 0;
}

void Get_User_Details()
{
    struct User *Current_User = (struct User*)malloc(sizeof(struct User));

    Current_User->User_Name = (char *)malloc(40*(sizeof(char)));
    Current_User->Mobile_Number = (int *)malloc(10*(sizeof(int )));
    Current_User->Email = (char *)malloc(80*(sizeof(char)));
    Current_User->Address = (char *)malloc(40*(sizeof(char)));
    char c;
    printf("Enter Your Name: ");
    scanf("%[^\n]%*c",Current_User->User_Name);
    printf("Enter Your Mobile Number: ");
    scanf("%d",Current_User->Mobile_Number);
    printf("Enter Your Email: ");
    scanf("%s",Current_User->Email);
    getchar();
    printf("Enter Your Address: ");
    scanf("%[^\n]%*c",Current_User->Address);

    free(Current_User);
}