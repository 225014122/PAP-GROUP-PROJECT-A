#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

int main(void) {
    int choice = 0;
    do {
        printf("\n=========================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM \n");
        printf("=========================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0;
        }

        switch (choice) {
            case 1: employeeMenu(); break;
            case 2: budgetManagement(); break;
            case 3: displaySupplierMenu(); break;
            case 4: assetMenu(); break;
            case 5: reportsMenu(); break;
            case 6: printf("Exiting system...\n"); break;
            default: printf("Invalid choice. Try again.\n"); break;
        }
    } while (choice != 6);

    return 0;
}