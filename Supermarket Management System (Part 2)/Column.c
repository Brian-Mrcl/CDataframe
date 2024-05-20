//
// Created by rayan on 10/05/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Column.h"

COLUMN* create_column(char* title) {
    COLUMN* column = (COLUMN*) malloc(sizeof(COLUMN));
    if (column == NULL) {
        fprintf(stderr, "Failed to allocate memory for column\n");
        return NULL;
    }
    column->title = strdup(title);
    column->data = (Article*) malloc(sizeof(Article) * 2); // Initial allocation
    column->physical_size = 2;
    column->logical_size = 0;

    return column;
}

int insert_article(COLUMN *col, Article article) {
    if (col->logical_size == col->physical_size) {
        col->physical_size *= 2;
        Article *new_data = (Article *)realloc(col->data, sizeof(Article) * col->physical_size);
        if (new_data == NULL) {
            return 0;
        }
        col->data = new_data;
    }
    col->data[col->logical_size] = article;
    col->logical_size++;
    return 1;
}

void delete_article(COLUMN *col, int index) {
    if (index < 0 || index >= col->logical_size) {
        printf("Invalid index!\n");
        return;
    }
    free(col->data[index].name);
    for (int i = index; i < col->logical_size - 1; i++) {
        col->data[i] = col->data[i + 1];
    }
    col->logical_size--;
    printf("Article deleted successfully.\n");
}

void print_col(COLUMN *col) {
    printf("Storage of %s:\n",col->title);
    for (int i = 0; i < col->logical_size; i++) {
        printf("\n[%d] Name: %s, Price: %d, Quantity: %d, Reduction: %d\n", i, col->data[i].name, col->data[i].price, col->data[i].quantity, col->data[i].reduction);
    }
    printf("\n");
}

void delete_column(COLUMN **col) {
    if (col != NULL && *col != NULL) {
        free((*col)->title);
        for (int i = 0; i < (*col)->logical_size; i++) {
            free((*col)->data[i].name);
        }
        free((*col)->data);
        free(*col);
        *col = NULL;
    }
}

void price_under_n(COLUMN *col,int n){
    for (int i = 0; i < col->logical_size; i++) {
        if(col->data[i].price <= n){
            printf("\n[%d] Name: %s, Price: %d, Quantity: %d, Reduction: %d\n", i, col->data[i].name, col->data[i].price, col->data[i].quantity, col->data[i].reduction);
        }
    }
}

void Reduc_catalog(COLUMN *col){
    COLUMN *Thecatalog = create_column("Articles in reductions");
    for (int i = 0; i < col->logical_size; i++) {
        if(col->data[i].reduction != 0){
            insert_article(Thecatalog, col->data[i]);
        }
    }
    print_col(Thecatalog);
    delete_column(&Thecatalog); // Ensure to free allocated memory
}

void search_by_name(COLUMN *col, const char *name) {
    printf("Search results for '%s':\n", name);
    int found = 0;
    for (int i = 0; i < col->logical_size; i++) {
        if (strcmp(col->data[i].name, name) == 0) {
            printf("Index : %d, Name: %s, Price: %d, Quantity: %d, Reduction: %d\n", i , col->data[i].name, col->data[i].price, col->data[i].quantity, col->data[i].reduction);
            found = 1;
        }
    }
    if (!found) {
        printf("No items found with the name '%s'\n", name);
    }
}

void update_article(COLUMN *col) {
    printf("Enter the index of the article you want to update: ");
    int index;
    scanf("%d", &index);
    if (index < 0 || index >= col->logical_size) {
        printf("Invalid index! There is no article located at this index. To verify the location of an article, use the search by name function.\n");
        return;
    }
    printf("What do you want to update?\n");
    printf("1. Name\n");
    printf("2. Price\n");
    printf("3. Quantity\n");
    printf("4. Reduction\n");
    int choice;
    scanf("%d", &choice);
    char buffer[256]; // buffer to store the new name
    switch (choice) {
        case 1:
            printf("Enter the new name: ");
            scanf("%s", buffer);
            free(col->data[index].name);
            col->data[index].name = strdup(buffer);
            break;
        case 2:
            printf("Enter the new price: ");
            scanf("%d", &col->data[index].price);
            break;
        case 3:
            printf("Enter the new quantity: ");
            scanf("%d", &col->data[index].quantity);
            break;
        case 4:
            printf("Enter the new reduction: ");
            scanf("%d", &col->data[index].reduction);
            break;
        default:
            printf("Invalid choice!\n");
    }
}