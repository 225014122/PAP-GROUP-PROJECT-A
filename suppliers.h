#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

typedef struct
{
    int supplierID;
    char name[100];
    char email[100];
    char telephone[30];
    char location[100];

} Supplier;

/* Supplier Management Functions */
void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);

#endif
