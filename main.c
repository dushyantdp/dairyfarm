#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

struct customer
{
    char name[100];
    char id[15];
    char mob[12];
    char type[10];
    char adr[100];
};

void Add_New_customer();
void Copy_files(FILE *, FILE *);

int main()
{
    struct customer data;

    char ch = 'y';

    while (ch == 'y' || ch == 'Y')
    {
        printf("--------------------------------------\n");
        printf("\tDairy management system\n");
        printf("--------------------------------------\n");

        printf("Select the following option to work:\n");
        int choice;
        printf("1. Add New Customer Name\n2. Edit Customer Details\n3. Search Details\n4. Add Milk\n5. Print Details\n");
        printf("Select the opton from 1 to 4 : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("adding new customer\n");
            Add_New_customer();
            // add new customer function();
            break;
        case 2:
            printf("editing mode\n");
            // edit customer function
            break;
        case 3:
            printf("searching mode\n");
            // search details function
            break;
        case 4:
            printf("Adding milk\n");
            // add milk function
            break;
        case 5:
            printf("printing details\n");
            // add milk function
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
        printf("Do you want to continue (Y/N)  :  ");
        scanf(" %c", &ch);
    }
    return 0;
}

void Copy_files(FILE *fptr, FILE *fptr1)
{
    char ch;
    while ((ch = fgetc(fptr1)) != EOF)
    {
        fputc(ch, fptr);
    }
}

void Add_New_customer()
{

    FILE *fptr = fopen("dairybook.csv", "r");
    FILE *fptr1 = fopen("temp.csv", "w");

    struct customer data;

    int count = 0;
    fscanf(fptr, "%d\n", &count);
    count++;
    fprintf(fptr1, "%d\n", count);

    for (int i = 0; i < count - 1; i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", data.name, data.id, data.mob, data.type, data.adr);
        fprintf(fptr1, "%s,%s,%s,%s,%s\n", data.name, data.id, data.mob, data.type, data.adr);
    }
    system("clear");
    printf("------------------------------------------\n");
    printf("\tEnter the customer details\n");
    printf("------------------------------------------\n");

    printf("Enter the name of the customer : ");
    scanf(" %[^\n]", data.name);

    printf("Enter the customer Id : ");
    scanf(" %[^\n]", data.id);

    printf("Enter the mobile number : ");
    scanf(" %[^\n]", data.mob);

    printf("Enter the Animal type : ");
    scanf(" %[^\n]", data.type);

    printf("Enter the Address : ");
    scanf(" %[^\n]", data.adr);

    fprintf(fptr1, "%s,%s,%s,%s,%s\n", data.name, data.id, data.mob, data.type, data.adr);
    fclose(fptr);
    fclose(fptr1);
    fptr = fopen("dairybook.csv", "w");
    fptr1 = fopen("temp.csv", "r");
    Copy_files(fptr, fptr1);
    fclose(fptr);
    fclose(fptr1);
}
//dushyants code starts from here
