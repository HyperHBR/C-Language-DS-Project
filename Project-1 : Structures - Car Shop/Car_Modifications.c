// By HyperHBR--Hardiksinh Rathod 
// Date--
// Program Name--

#include <stdio.h>
#include <math.h>
#include <string.h>

struct Modification_Types // Structure For Storing Modification Details
{
    int Mod_Type_Code;
    char Mod_Type[25];
    int Mod_Starts_At;
    int Mod_Ends_At;
};

struct Modification_Types Mod_Types[6] = {
                                            1, "Wheels",0,4,
                                            2, "Vents",4,5,
                                            3, "Lights",5,9,
                                            4, "Spoiler",9,11,
                                            5, "Side_Skirts(Exhaust)",11,13,
                                            6, "Car_Stereo(Sound System)",13,14};

struct Modifications // Structure For Storing Modification Details
{
    int Mod_Code;
    char Mod_Name[25];
    int Mod_Cost;
};

struct Modifications Car_Modification[14]=
{
    1,"Atomic         ",2000,
    2,"Off road wheel ",4000,
    3,"Twist          ",3000,
    4,"Mega           ",2500,
    5,"Roof Scoop     ",4000,
    6,"Tail Light     ",3000,
    7,"Polo Light     ",5000,
    8,"Fog Light      ",8000,
    9,"White LED Light",12000,
    10,"Win            ",12000,
    11,"Alpha          ",10000,
    12,"Medium Exhaust ",6000,
    13,"Twin Exhaust   ",8000,
    14,"Boost Bass     ",15000,
};

int RangeCheck(int i,int low,int high)
{
    if(i>=low && i<=high)
        return 1;
    else
        return 0;
}

int main()
{
    int Mod_Choice_Array[6];
    int Current_Mod_Type;
    int Mod_Selected;
    char More_Mods = 'Y';

    while(More_Mods == 'Y')
    {

        printf("\nThese Are All The Available Car Modifications Types:\n");
        for(int i=0;i<sizeof(Mod_Types)/sizeof(struct Modification_Types);i++)
            printf("0%d - %s\n",Mod_Types[i].Mod_Type_Code,Mod_Types[i].Mod_Type);
        
        printf("\nWhich Car Modification Do You Want To Opt For : ");
        scanf("%d",&Current_Mod_Type);

        if(RangeCheck(Current_Mod_Type,1,6))
        {
            for(int i=Mod_Types[Current_Mod_Type-1].Mod_Starts_At;i<Mod_Types[Current_Mod_Type-1].Mod_Ends_At;i++)
                printf("%d - %s - Rs.%d\n",Car_Modification[i].Mod_Code,Car_Modification[i].Mod_Name,Car_Modification[i].Mod_Cost);
        }
        else
        {
            printf("\nInvalid Choice\n");
            main();
        }

        printf("\nWhich %s Type Would You Like Us To Implement: ",Mod_Types[Current_Mod_Type-1].Mod_Type);
        scanf("%d",&Mod_Selected);

        if(!RangeCheck(Mod_Selected,Mod_Types[Current_Mod_Type-1].Mod_Starts_At+1,Mod_Types[Current_Mod_Type-1].Mod_Ends_At))
        {
            printf("\nInvalid Choice\n");
            main();
        }

        printf("\nDo You Want To Apply More Modifications(Y/N) :");
        getchar();
        scanf("%c",&More_Mods);

        if(More_Mods != 'Y' && More_Mods !='N')
        {
            printf("\n\nInvalid Choice!!!\n\n");
            More_Mods = 'Y';
            continue;
        }
    }

    return 0;
}