#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Column.h"

#define REALOC_SIZE 256


COLUMN* create_column(char* title) {
    COLUMN* column = (COLUMN*) malloc(sizeof(COLUMN));
    if (column == NULL) {
        fprintf(stderr, "Failed to allocate memory for column\n");
        return NULL;
    }
    column->title = strdup(title);
    column->data = NULL;
    column->physical_size = 0;
    column->logical_size = 0;

    return column;
}

int insert_value(COLUMN *col, int value) {
    if (col->logical_size == col->physical_size) {
        col->physical_size *= 2;
        int *new_data = (int *)realloc(col->data, sizeof(int) * col->physical_size);
        if (new_data == NULL) {
            return 0;
        }
        col->data = new_data;
    }
    col->data[col->logical_size] = value;
    col->logical_size++;
    return 1;
}

void delete_column(COLUMN **col) {
    if (col != NULL && *col != NULL) {
        free((*col)->title);
        free((*col)->data);
        free(*col);
        *col = NULL;
    }
}

void print_col(COLUMN *col) {
    printf("Data in the COLUMN:\n");
    for (int i = 0; i < col->logical_size; i++) {
        printf("\n[%d] %d ",i ,col->data[i]);
    }
    printf("\n");
}

int count_occurrences(const COLUMN *col, int x) {
    int count = 0;
    for (int i = 0; i < col->logical_size; i++) {
        if (col->data[i] == x) {
            count++;
        }
    }
    return count;
}

int get_value(COLUMN *col, int x){
// Just in case the index is not a valid one
    if (x < 0 || x >= col->logical_size) {
        return 0;
    }
    return col -> data[x];
}

int retgreater(COLUMN *col, int x){
    int count = 0;
    for(int i =0; i < col-> logical_size;i++){
        if(col->data[i] > x){
            count++;
        }
    }
    return count;
}

int retless(COLUMN *col, int x){
    int count = 0;
    for(int i =0; i < col-> logical_size;i++){
        if(col->data[i] < x){
            count++;
        }
    }
    return count;
}

int count_values_equal_to(COLUMN *col, int x) {
    int count = 0;
    for (int i = 0; i < col->logical_size; i++) {
        if (col->data[i] == x) {
            count++;
        }
    }
    return count;
}