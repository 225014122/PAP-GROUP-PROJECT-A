#include <stdio.h>

#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

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
            highestSalary = salary;

        if(salary < lowestSalary)
            lowestSalary = salary;
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
}

/* Supplier Report */
void supplierReport(void)
{
    printf("\n========================================\n");
    printf("          SUPPLIER REPORT\n");
    printf("========================================\n");

    printf("Supplier records are managed in the\n");
    printf("Supplier Management module.\n");
}

/* Asset Report */
void assetReport(void)
{
    printf("\n========================================\n");
    printf("            ASSET REPORT\n");
    printf("========================================\n");

    printf("Asset records are managed in the\n");
    printf("Asset Management module.\n");
}

/* Reports Menu */
void reportsMenu(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("            REPORTS MENU\n");
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