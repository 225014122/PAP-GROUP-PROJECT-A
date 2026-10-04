#ifndef ASSET_MANAGEMENT_H
#define ASSET_MANAGEMENT_H

#include <stdio.h>

#define MAX_ASSETS 100
#define DATA_FILE  "assets.txt"
#define LINE_SIZE  256

#define ID_SIZE    20
#define NAME_SIZE  50
#define TYPE_SIZE  30
#define DEPT_SIZE  50
#define COND_SIZE  30

struct Asset
{
    char   assetID[ID_SIZE];
    char   assetName[NAME_SIZE];
    char   assetType[TYPE_SIZE];
    double purchaseValue;
    char   department[DEPT_SIZE];
    char   condition[COND_SIZE];
};

extern struct Asset assets[MAX_ASSETS];
extern int assetCount;

void   getLine(const char *prompt, char *line, int size);
void   readLine(const char *prompt, char *dest, int size);
int    readInt(const char *prompt);
double readPositiveDouble(const char *prompt);

int    equalsIgnoreCase(const char *a, const char *b);
int    findAsset(const char *id);

void   saveAssets(void);
int    readFileLine(FILE *fp, char *dest, int size);
void   loadAssets(void);

void   printAsset(const struct Asset *a);
void   addAsset(void);
void   displayAssets(void);
void   searchAsset(void);

void   assetMenu(void);

#endif
