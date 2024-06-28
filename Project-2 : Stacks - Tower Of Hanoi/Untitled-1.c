#include <stdio.h> //For Basic Input Output Processes
#include <math.h> //For Mathematical Manupulations
#include <string.h> //For String Manupulations
#include <stdlib.h> //For Dynamic Memory Allocation

int level = 0; //For Height Of Tournament
int storecounter = 0; //For BackTracking Purpose
int counter = 0; //For Reaching The Exact Line

//Structure Of Device
struct device_name
{
    char device_name[20]; //Storing Names Of Devices
};

//Array Of Devices
struct device_name device[20] = {
    "samsung  ", "nokia    ", "oneplus  ", "lenovo   ", "hp       ", "dell     ", "asus     ", "apple    ", "vivo     ", "oppo     ", "motorola ", "acer     ", "techno   ", "pixel    ", "redmi    ", "msi      ", "razer    ", "sony     ", "LG       ", "JIO      "};

//Structure Of Storing
struct storing
{
    struct Node *root;
};
// struct Node *store[100];

//Structure Of Node
struct Node
{
    int value;            // For Searching Afterwards
    char ip[20];          // Setting The IP Of Device
    char device_name[20]; // Name Of Device
    char mac_address[20]; // Mac Address Of Device
    struct Node *left; //For Connecting Left Node
    struct Node *right; //For Connecting Right Node
};

//Function To Create The Node
struct Node *createNode(int value) //,int ip,char device_name[20],char country[15],char mac_address[12]) //Function To Create The Node
{
    struct Node *n;                                 // Creating A Node Pointer
    n = (struct Node *)malloc(sizeof(struct Node)); // Allocating Memory In The Heap
    n->value = value;                               // For Furthur Use
    n->left = NULL;                                 // Setting Initial Connection To NULL
    n->right = NULL;                                // Setting Initial Connection To NULL
    return n; // Returning The Created Node;
}

// The Main Function To Creating And Connecting All The Nodes 
struct Node *createNodesToLevel(double n, int level, struct Node *root)
{

    if (n >= 1 && level >= 1)
    {
        root->value = n;
        assigning(root);
        // printf("%.f ", n);
        if (level == 2)
        {

            root->left = createNode(0);
            root->right = createNode(0);
            createNodesToLevel(n - 1, level - 1, root->left);
            createNodesToLevel(n + 1, level - 1, root->right);
        }
        else if (level > 1)
        {
            root->left = createNode(0);
            root->right = createNode(0);
            createNodesToLevel(n - pow(2, level - 2), level - 1, root->left);
            createNodesToLevel(n + pow(2, level - 2), level - 1, root->right);
        }
    }
}

//The Main Function
int main()
{
    system("cls||clear"); //For Clearing The Screen
    struct Node *root = createNode(0); //Creating The Root Node

    srand(time(0)); //The Random Function
    int t;

    printf("Enter The Number Of Devices You Want(It Should In The Power Of 2): ");
    scanf("%d", &t);

    int level = log2(t) + 1; //Basic Formula To Calculate The Number Of Levels

    createNodesToLevel(t, level, root); //Calling The Create Node Function
    deviceFile(root); // For Value Assignment

    char ch;
    printf("Do You Want To See All The Devices Which Have Been Created(Y/N): ");

    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        printdevice(); //Call The Print Device Function To Print The Devices
    }

    choice(root); //For Getting The Specific Path Of Device

    return 0;
}

//Function For Inorder Traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

//Function For Postorder Traversal
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}

//Function For Preorder Traversal
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

//For Assign Values From The File
void assigning(struct Node *root)
{
    FILE *ptr; //Creating A File Pointer
    FILE *ptr_mac; //For Creating A File Pointer
    ptr = fopen("1.txt", "r"); //Opening The 1.txt File
    ptr_mac = fopen("2.txt", "r"); //Opening The 2.txt File

    //For Getting The Ip And Mac Address
    for (int i = 0; i <= counter; i++)
    {
        fgets(root->ip, 20, ptr);
        fgets(root->mac_address, 20, ptr_mac);
    }
    //Closing The File
    fclose(ptr);

    //Incrementing Counter For New Lines
    counter++;
}

//For Device Related Finle Handling
void deviceFile(struct Node *root)
{
    if (root != NULL) //Checking Whether Root Is Null Or Not
    {
        if (root->left == NULL && root->right == NULL)
        {
            FILE *ptr = fopen("3.txt", "a"); //For Creating A File Pointer And Opening The 3.txt File In Append Mode
            int r = rand() % 20; //Generating A Random Value From 0 to 19

            for (int i = 0; i < 10; i++)
            {
                root->device_name[i] = device[r].device_name[i];
            }

            //When We Are Using Append We Need To Use It
            fflush(stdin);
            //For Printing
            fputs(root->device_name, ptr);
            fputs(" :\t", ptr);
            //For Printing
            fputs(root->ip, ptr);
            fputs("\t", ptr);
            //For Printing
            fputs(root->mac_address, ptr);
            fputs("\n", ptr);
            //Closing The File Pointer
            fclose(ptr);
        }
        else
        {
            //If The Node Is Not A Leaf Node Then Print It
            strcpy(root->device_name, "router");
        }
        
        //Using Recursion For Full Tree
        deviceFile(root->left);
        deviceFile(root->right);
    }
}

//For Printing Device Details
void printdevice()
{
    FILE *ptr; //Creating A File Pointer
    char ch;
    char ch2 = 'Y';
    ptr = fopen("3.txt", "r"); //Opening The 3.txt File In Read Mode

    // If File Does Not Exist Or If It Is Not In Read Mode
    if (NULL == ptr)
    {
        printf("File Can't Be Opened \n");
    }

    printf("All The Name Of The Devices With Their Ip Address And Mac: \n");

    //Looping Till End Of File
    while (!feof(ptr))
    {
        ch = fgetc(ptr);
        printf("%c", ch);
    }
}

//For Backtracking And Printing
void Store(struct Node *root, struct Node *store[], int value)
{

    backtracking(root, store, value);
    print(root, store);
}

//For Printing In Our File
void print(struct Node *root, struct Node *store[])
{
    char ch;

    printf("-----------------------------------------\n");
    for (int i = 0; i < storecounter; i++)
    {
        printf("\n");
        printf("Level %d\n",i+1);
        printf("The IP -->>  %s", store[i]->ip);
        printf("The Mac Address-->>  %s\n", store[i]->mac_address);
        printf("-----------------------------------------\n");
    }
    storecounter = 0;

    printf("Do You Want To Continue[Y/N]: ");
    scanf(" %c", &ch);
    if (ch == 'Y' || ch == 'y')
    {
        choice(root); //Calling The Choice Function
    }
    else
    {
        exit(0);
    }
}

//For Backtracking
void backtracking(struct Node *root, struct Node *store[], int value)
{
    //In Case The Root Is Encountered
    if (value == root->value)
    {
        store[storecounter] = root; //Storing It In Array
    }
    //Incase The Value Is Greater Than The Root
    else if (value > root->value)
    {
        store[storecounter] = root; //Storing It In Array
        storecounter++; //Incrementing Store Counter To Point To Next Location In Array
        backtracking(root->right, store, value); //For Recurrsion
    }
    //Incase The Value Is Lesser Than The Root
    else if (value < root->value)
    {
        store[storecounter] = root; //Storing It In Array
        storecounter++; //Incrementing Store Counter To Point To Next Location In Array
        backtracking(root->left, store, value); //For Recurrsion
    }
}

//Do U Want To Continue
void choice(struct Node *root)
{
    char ch;
    struct Node store[100];

    //Asking The User
    printf("Do you want to see all the sub routers which have been connected to it[y/n]: ");
    scanf(" %c", &ch);

    if (ch == 'Y' || ch == 'y')
    {
        int n;
        printf("Enter the number of the device you want to see: ");
        scanf(" %d", &n);
        int value = 1 + (n - 1) * 2;
        Store(root, store, value);
    }
}