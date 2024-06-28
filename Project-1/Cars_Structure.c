// By HyperHBR--Hardiksinh Rathod 
// Date--
// Program Name--

#include <stdio.h>
#include <math.h>
#include <string.h>

struct Car_Brands
{
    int Brand_Code;
    char Model[25];
    int Car_Model_Starts_At;
    int Car_Model_Ends_At;
};

struct Car_Brands Brands[7] = {
                                1, "Kia",0,3,
                                2, "Hyundai",3,8,
                                3, "Honda",8,11,
                                4, "Mahindra",11,16,
                                5, "Maruti Suzuki",16,21,
                                6, "Mercedez",21,25,
                                7, "Toyota",25,28
                                };

struct Car_Model // Structure For Storing Car Model Details
{
    int Car_Code;
    char Model[25];
    int Car_Cost;
};

struct Car_Model Models[29] = {
                                1,"Kia Sonet",    1379000,
                                2,"Kia Seltos",   1865000,
                                3,"Kia Carnival", 3549000,
                                4,"Hyundai Santro",   489000,
                                5,"Hyundai i10",  539000,
                                6,"Hyundai i20",  703000,
                                7,"Hyundai Verna",    940000,
                                8,"Hyundai Creta",    1044000,
                                9,"Honda City",   950000,
                                10,"Honda Amaze",  665000,
                                11,"Honda Jazz",   811000,
                                12,"Mahindra Thar",    1353000,
                                13,"Mahindra XUV 300", 841000,
                                14,"Mahindra XUV 500", 931000,
                                15,"Mahindra XUV 700", 1318000,
                                16,"Mahindra Scropio", 1199000,
                                17,"Maruti Suzuki Swift",  591000,
                                18,"Maruti Suzuki Baleno", 642000,
                                19,"Maruti Suzuki Ertiga", 835000,
                                20,"Maruti Suzuki Brezza", 799000,
                                21,"Maruti Suzuki S-Cross",    950000,
                                22,"Mercedez S-Class", 16000000,
                                23,"Mercedez C-Class", 5500000,
                                24,"Mercedez AMG", 17200000,
                                25,"Mercedez Benz",    4490000,
                                26,"Toyota Camry", 4435000,
                                27,"Toyota Innova",    1786000,
                                28,"Toyota Fortuner",  3239000,
                                29,"Toyota Land Cruiser",  902000,
                                };

struct Car_Colour
{
    int Colour_Code;
    char Colour_Name[20];
};

struct Car_Colour Colours[7] = {
                                1, "Black",
                                2, "White",
                                3, "Red",
                                4, "Blue",
                                5, "Dark Green",
                                6, "Grey",
                                7, "Yellow"};

int RangeCheck(int i,int low,int high)
{
    if(i>=low && i<=high)
        return 1;
    else
        return 0;
}

int main()
{
    int Brand_Choice;
    int Car_Colour;
    int Car_Chosen;

    printf("These Are All The Available Car Brands:\n");
    for(int i=0;i<sizeof(Brands)/sizeof(struct Car_Brands);i++)
        printf("0%d - %s\n",Brands[i].Brand_Code,Brands[i].Model);
    
    printf("\nWhich Car Brand You Want To Select: ");
    scanf("%d",&Brand_Choice);

    if(RangeCheck(Brand_Choice,1,7))
    {
        for(int i=Brands[Brand_Choice-1].Car_Model_Starts_At;i<Brands[Brand_Choice-1].Car_Model_Ends_At;i++)
            printf("%d - %s - Rs.%d\n",Models[i].Car_Code,Models[i].Model,Models[i].Car_Cost);
    }
    else
    {
        printf("\nInvalid Choice\n");
        main();
    }

    printf("\nWhich Car Would You Like To Buy: ");
    scanf("%d",&Car_Chosen);

    if(!RangeCheck(Car_Chosen,Brands[Brand_Choice-1].Car_Model_Starts_At+1,Brands[Brand_Choice-1].Car_Model_Ends_At))
    {
        printf("\nInvalid Choice\n");
        main();
    }

    printf("\nThese Are All The Available Car Colours:\n");
    for(int i=0;i<sizeof(Colours)/sizeof(struct Car_Colour);i++)
        printf("0%d - %s\n",Colours[i].Colour_Code,Colours[i].Colour_Name);
    
    printf("\nWhich Car Colour Would You Like To Opt For: ");
    scanf("%d",&Car_Colour);

    return 0;
}