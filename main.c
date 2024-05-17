#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"


int main() {
    int BOOL = 1;
    while (BOOL == 1) {
        int choose_value;
        printf("1. Create a name shop (column)\nChoose the option : ");
        scanf("%d", &choose_value);

        if (choose_value == 1) {
            char name[50];
            printf("Enter the name of your shop (column) : ");
            scanf("%s", name);
            COLUMN *myColumn = create_column(name);
            // Add more code here if you want to do something with myColumn
        }
        BOOL = 0;
    }

    /*
    // Create a column
    COLUMN *myColumn = create_column("Electronics");

    // Create some articles
    Article article1 = {strdup("Laptop"), 1000, 10, 0};
    Article article2 = {strdup("Smartphone"), 600, 5, 10};
    Article article3 = {strdup("Headphones"), 100, 15, 5};
    Article article4 = {strdup("Monitor"), 300, 7, 0};

    // Insert articles into the column
    insert_article(myColumn, article1);
    insert_article(myColumn, article2);
    insert_article(myColumn, article3);
    insert_article(myColumn, article4);

    // Print all articles in the column
    print_col(myColumn);

    // Search for an article by name
    search_by_name(myColumn, "Smartphone");

    // Update an article
    update_article(myColumn);

    // Print all articles in the column again to see the update
    print_col(myColumn);

    // Print articles with price under a certain value
    printf("Articles with price under 500:\n");
    price_under_n(myColumn, 500);

    // Print articles with reductions
    printf("Articles with reductions:\n");
    Reduc_catalog(myColumn);

    // Delete an article by index
    delete_article(myColumn, 2);

    // Print all articles in the column again to see the deletion
    print_col(myColumn);

    // Clean up and free memory
    delete_column(&myColumn);
    */

    return 0;
}