#include <stdio.h>

#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "asset.h"

void clearInputBuffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

/* Employee Report */
void employeeReport(void)
{
    if(employeeCount == 0)
    {
        printf("\nNo employees available.\n");
        return;
    }

    float totalSalary = 0;

    float highestSalary =
        employees[0].basicSalary +
        employees[0].housingAllowance +
        employees[0].transportAllowance;

    float lowestSalary = highestSalary;

    for(int i = 0; i < employeeCount; i++)
    {
        float salary =
            employees[i].basicSalary +
            employees[i].housingAllowance +
            employees[i].transportAllowance;

        totalSalary += salary;

        if(salary > highestSalary)
        {
            highestSalary = salary;
        }

        if(salary < lowestSalary)
        {
            lowestSalary = salary;
        }
    }

    printf("\n========================================\n");
    printf("          EMPLOYEE REPORT\n");
    printf("========================================\n");

    printf("Total Employees : %d\n", employeeCount);

    printf("Average Salary  : N$%.2f\n",
           totalSalary / employeeCount);

    printf("Highest Salary  : N$%.2f\n",
           highestSalary);

    printf("Lowest Salary   : N$%.2f\n",
           lowestSalary);
}

/* Budget Report */
void budgetReport(void)
{
    float totalAllocated = 0;
    float totalExpenditure = 0;
    float totalRemaining = 0;

    printf("\n========================================\n");
    printf("            BUDGET REPORT\n");
    printf("========================================\n");

    for(int i = 0; i < numberOfDepartments; i++)
    {
        totalAllocated += allocatedBudget[i];
        totalExpenditure += expenditure[i];
        totalRemaining += remainingBudget[i];
    }

    printf("Total Allocated Budget : N$%.2f\n",
           totalAllocated);

    printf("Total Expenditure      : N$%.2f\n",
           totalExpenditure);

    printf("Total Remaining Budget : N$%.2f\n",
           totalRemaining);

    printf("\nDepartments Over Budget:\n");

    int found = 0;

    for(int i = 0; i < numberOfDepartments; i++)
    {
        if(expenditure[i] > allocatedBudget[i])
        {
            printf("- %s\n", department[i]);
            found = 1;
        }
    }

    if(found == 0)
    {
        printf("None\n");
    }
}

/* Supplier Report */
void supplierReport(void)
{
    if(supplierCount == 0)
    {
        printf("\nNo suppliers available.\n");
        return;
    }

    printf("\n========================================\n");
    printf("           SUPPLIER REPORT\n");
    printf("========================================\n");

    for(int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);

        printf("Supplier ID : %d\n",
               suppliers[i].supplierID);

        printf("Name        : %s\n",
               suppliers[i].name);

        printf("Email       : %s\n",
               suppliers[i].email);

        printf("Telephone   : %s\n",
               suppliers[i].telephone);

        printf("Location    : %s\n",
               suppliers[i].location);
    }
}

/* Asset Report */
void assetReport(void)
{
    if(assetCount == 0)
    {
        printf("\nNo assets available.\n");
        return;
    }

    printf("\n========================================\n");
    printf("             ASSET REPORT\n");
    printf("========================================\n");

    for(int i = 0; i < assetCount; i++)
    {
        printf("\nAsset ID       : %s\n",
               assets[i].assetID);

        printf("Asset Name     : %s\n",
               assets[i].assetName);

        printf("Asset Type     : %s\n",
               assets[i].assetType);

        printf("Purchase Value : N$%.2lf\n",
               assets[i].purchaseValue);

        printf("Department     : %s\n",
               assets[i].department);

        printf("Condition      : %s\n",
               assets[i].condition);
    }
}

/* Reports Menu */
void reportsMenu(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("             REPORTS MENU\n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back\n");

        printf("Enter choice: ");

        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice)
        {
            case 1:
                employeeReport();
                break;

            case 2:
                budgetReport();
                break;

            case 3:
                supplierReport();
                break;

            case 4:
                assetReport();
                break;

            case 5:
                printf("\nReturning...\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while(choice != 5);
}