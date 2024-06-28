int ch, ele;
    while (1)
    {
        printf("-----------------------Music Player Operations-----------------------");
        printf("\n1-To Enter An Item.");
        printf("\n2-To Remove The First Element.");
        printf("\n3-To See All The Elements Entered.");
        printf("\n4-To Exit");

        printf("\nEnter The Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter The Item: ");
            scanf("%d", &ele);
            enqueue(q, ele);
            system("clear");
            printf("\nElement Has Been Entered.\n");
            break;
        case 2:
            dequeue(q);
            system("clear");
            printf("\nElement Has Been Removed\n");
            break;
        case 3:
            system("clear");
            traverseQueue(q);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Choice...\n");
            printf("Please Enter Again...\n");
            break;
        }
    }
    return 0;