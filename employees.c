#include <stdio.h>
#include <string.h>
#include "employees.h"

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

static void clearBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void employeeMenu(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("         EMPLOYEE MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search for Employee\n");
        printf("4. Calculate Employee Salary\n");
        printf("5. Back to Main Menu\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            clearBuffer();
            choice = -1;
        }
        else
        {
            clearBuffer();
        }

        switch (choice)
        {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: calculateEmployeeSalary(); break;
            case 5: break;
            default: printf("Invalid choice. Please enter 1-5.\n");
        }

        if (choice != 5)
        {
            printf("\nPress Enter to continue...");
            clearBuffer();
        }

    } while (choice != 5);
}

void addEmployee(void)
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("System full. Cannot add more employees.\n");
        return;
    }

    printf("\n--- Add New Employee ---\n");

    printf("Enter Employee ID: ");
    scanf("%d", &employees[employeeCount].id);
    clearBuffer();

    do
    {
        printf("Enter Employee Name: ");
        fgets(employees[employeeCount].name, 50, stdin);
        employees[employeeCount].name[strcspn(employees[employeeCount].name, "\n")] = '\0';

        if (strlen(employees[employeeCount].name) == 0)
        {
            printf("Name cannot be empty.\n");
        }
    } while (strlen(employees[employeeCount].name) == 0);

    printf("Enter Department: ");
    fgets(employees[employeeCount].department, 50, stdin);
    employees[employeeCount].department[strcspn(employees[employeeCount].department, "\n")] = '\0';

    do
    {
        printf("Enter Basic Salary: N$");
        scanf("%f", &employees[employeeCount].basicSalary);
        clearBuffer();

        if (employees[employeeCount].basicSalary < 0)
        {
            printf("Salary cannot be negative.\n");
        }
    } while (employees[employeeCount].basicSalary < 0);

    do
    {
        printf("Enter Housing Allowance: N$");
        scanf("%f", &employees[employeeCount].housingAllowance);
        clearBuffer();

        if (employees[employeeCount].housingAllowance < 0)
        {
            printf("Allowance cannot be negative.\n");
        }
    } while (employees[employeeCount].housingAllowance < 0);

    do
    {
        printf("Enter Transport Allowance: N$");
        scanf("%f", &employees[employeeCount].transportAllowance);
        clearBuffer();

        if (employees[employeeCount].transportAllowance < 0)
        {
            printf("Allowance cannot be negative.\n");
        }
    } while (employees[employeeCount].transportAllowance < 0);

    employeeCount++;
    printf("\nEmployee added successfully!\n");
}

void displayEmployees(void)
{
    int i;

    if (employeeCount == 0)
    {
        printf("\nNo employees in the system yet.\n");
        return;
    }

    printf("\n--- All Employees ---\n");

    for (i = 0; i < employeeCount; i++)
    {
        printf("\nID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Basic Salary: N$%.2f\n", employees[i].basicSalary);
        printf("Housing Allowance: N$%.2f\n", employees[i].housingAllowance);
        printf("Transport Allowance: N$%.2f\n", employees[i].transportAllowance);
    }
}

void searchEmployee(void)
{
    int i;
    int searchId;
    char searchName[50];
    int found = 0;
    int choice;

    if (employeeCount == 0)
    {
        printf("\nNo employees to search.\n");
        return;
    }

    printf("\nSearch by:\n1. ID\n2. Name\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    clearBuffer();

    if (choice == 1)
    {
        printf("Enter Employee ID: ");
        scanf("%d", &searchId);
        clearBuffer();

        for (i = 0; i < employeeCount; i++)
        {
            if (employees[i].id == searchId)
            {
                printf("\nEmployee Found!\n");
                printf("ID: %d\n", employees[i].id);
                printf("Name: %s\n", employees[i].name);
                printf("Department: %s\n", employees[i].department);
                found = 1;
                break;
            }
        }
    }
    else if (choice == 2)
    {
        printf("Enter Employee Name: ");
        fgets(searchName, 50, stdin);
        searchName[strcspn(searchName, "\n")] = '\0';

        for (i = 0; i < employeeCount; i++)
        {
            if (strcmp(employees[i].name, searchName) == 0)
            {
                printf("\nEmployee Found!\n");
                printf("ID: %d\n", employees[i].id);
                printf("Name: %s\n", employees[i].name);
                printf("Department: %s\n", employees[i].department);
                found = 1;
                break;
            }
        }
    }

    if (!found)
    {
        printf("\nEmployee not found.\n");
    }
}

void calculateEmployeeSalary(void)
{
    int i, searchId, found = 0;
    float totalSalary;

    if (employeeCount == 0)
    {
        printf("\nNo employees in the system.\n");
        return;
    }

    printf("\nEnter Employee ID to calculate salary: ");
    scanf("%d", &searchId);
    clearBuffer();

    for (i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == searchId)
        {
            totalSalary = employees[i].basicSalary
                        + employees[i].housingAllowance
                        + employees[i].transportAllowance;

            printf("\n--- Salary Breakdown for %s ---\n", employees[i].name);
            printf("Basic Salary:      N$%.2f\n", employees[i].basicSalary);
            printf("Housing Allowance: N$%.2f\n", employees[i].housingAllowance);
            printf("Transport Allow.:  N$%.2f\n", employees[i].transportAllowance);
            printf("---------------------------------\n");
            printf("Total Salary:      N$%.2f\n", totalSalary);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Employee with ID %d not found.\n", searchId);
    }
}