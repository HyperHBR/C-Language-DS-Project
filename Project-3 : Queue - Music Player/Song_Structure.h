#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct Songs_Types
{
    int num;
    char type[30];
    int SongStartsFrom;
    int SongEndsAt;
};

struct Songs_Types Types[6] = {
                                1,"Hollywood Songs",0,4,
                                2,"Bollywood Songs",4,8,
                                3,"Punjabi Songs",8,13,
                                4,"Gujarati Songs",13,18,
                                5,"Garbo Songs",18,20,
                                6,"Old Bollywood Songs",20,23,
};

struct Song_Name_And_Codes
{
    int num;
    char name[30];
};

struct Song_Name_And_Codes Names_And_Codes[23]={
                                1, "See You Again",
                                3, "Closer", 
                                2, "Heat Waves", 
                                4, "Bella Ciao", 
                                5, "Kesariya", 
                                6, "Phir kabhi", 
                                7, "Tu Aake Dekhle", 
                                8, "Namo Namo", 
                                9, "We Rollin", 
                                10, "Brown Munde", 
                                11, "Back Bone", 
                                12, "Wakhra", 
                                13, "Lehanga", 
                                14, "Ganu Jeevo", 
                                15, "Shan Bhan Bhule", 
                                16, "Sapna Vinai Ni Raat", 
                                17, "Dhun Lagi", 
                                18, "Vhalam Aavo Ne", 
                                19, "Manada Lidha Mohi", 
                                20, "Vaagyo Re Dhol", 
                                21, "Lag Jaa Gale", 
                                22, "Kya Hua Tera Wada", 
                                23, "O Mere Dil Ke Chain",
                                };   