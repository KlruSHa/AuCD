#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* k;
    char* v;
} Item;

typedef struct {
    Item* a;
    int n;
} Table;

Table* create_table(int n);
void free_table(Table* t);
void sort_table(Table* t);
int find_item(Table* t, char* k);
void print_table(Table* t);
char* read_str();

#endif
