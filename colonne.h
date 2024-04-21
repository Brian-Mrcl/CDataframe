#include <stdio.h>
#include <stdlib.h>

#ifndef COLUMN_H
#define COLUMN_H


typedef struct COLUMN {
    char title;
    int data;
    int physical_size;
    int logical_size;
} COLUMN;

COLUMN* create_column(char* title);
int insert_value(COLUMN *col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN *col);
int count_occurrences(const COLUMN *col, int x);
int get_value(COLUMN *col, int x);
int retgreater(COLUMN *col, int x);
int retless(COLUMN *col, int x);
int count_values_equal_to(COLUMN *col, int x);
void display_menu();

#endif / COLUMN_H */