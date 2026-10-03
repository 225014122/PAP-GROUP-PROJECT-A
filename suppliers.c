#include <stdio.h>
#include <string.h>
#include "suppliers.h"

Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;

void addSupplier(void)
{
    printf("\n--- Add Supplier ---\n");

    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier storage is full.\n");
        return;
    }

    printf("Enter Supplier ID: ");
    scanf("%d", &suppliers[supplierCount].supplierID);

    getchar();

    printf("Enter Supplier Name: ");
    fgets(suppliers[supplierCount].name,
          sizeof(suppliers[supplierCount].name), stdin);

    suppliers[supplierCount].name[
        strcspn(suppliers[supplierCount].name, "\n")
    ] = '\0';

    printf("Enter Email: ");
    fgets(suppliers[supplierCount].email,
          sizeof(suppliers[supplierCount].email), stdin);

    suppliers[supplierCount].email[
        strcspn(suppliers[supplierCount].email, "\n")
    ] = '\0';

    printf("Enter Telephone Number: ");
    fgets(suppliers[supplierCount].telephone,
          sizeof(suppliers[supplierCount].telephone), stdin);

    suppliers[supplierCount].telephone[
        strcspn(suppliers[supplierCount].telephone, "\n")
    ] = '\0';

    printf("Enter Town/Location: ");
    fgets(suppliers[supplierCount].location,
          sizeof(suppliers[supplierCount].location), stdin);

    suppliers[supplierCount].location[
        strcspn(suppliers[supplierCount].location, "\n")
    ] = '\0';

    supplierCount++;

    printf("\nSupplier added successfully!\n");
}

void displaySuppliers(void)
{
    int i;

    printf("\n--- Supplier List ---\n");

    if (supplierCount == 0)
    {
        printf("No suppliers registered.\n");
        return;
    }

    for (i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Supplier ID: %d\n", suppliers[i].supplierID);
        printf("Name: %s\n", suppliers[i].name);
        printf("Email: %s\n", suppliers[i].email);
        printf("Telephone: %s\n", suppliers[i].telephone);
        printf("Town/Location: %s\n", suppliers[i].location);
    }
}

void searchSupplier(void)
{
    int id;
    int i;
    int found = 0;

    printf("\n--- Search Supplier ---\n");

    printf("Enter Supplier ID: ");
    scanf("%d", &id);

    for (i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].supplierID == id)
        {
            printf("\nSupplier Found!\n");
            printf("Supplier ID: %d\n", suppliers[i].supplierID);
            printf("Name: %s\n", suppliers[i].name);
            printf("Email: %s\n", suppliers[i].email);
            printf("Telephone: %s\n", suppliers[i].telephone);
            printf("Town/Location: %s\n", suppliers[i].location);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Supplier not found.\n");
    }
}
