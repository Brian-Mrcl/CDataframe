#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dataframe.h"


CDataframe* create_dataframe() {
    CDataframe* df = (CDataframe*) malloc(sizeof(CDataframe));
    df->columns = NULL;
    df->physical_size = 0;
    df->logical_size = 0;
    return df;
}

int add_column(CDataframe* df, COLUMN* col) {
    if (df->logical_size == df->physical_size) {
        int new_size = (df->physical_size == 0) ? 1 : df->physical_size * 2;
        COLUMN **new_columns = (COLUMN**) realloc(df->columns, sizeof(COLUMN*) * new_size);
        if (new_columns == NULL) {
            return 0;
        }
        df->columns = new_columns;
        df->physical_size = new_size;
    }
    df->columns[df->logical_size] = col;
    df->logical_size++;
    return 1;
}



void add_shelf(CDataframe* df) {
    char col_name[256];
    printf("Enter the name of the new shelf: ");
    fflush(stdin); // Clear the input buffer
    fgets(col_name, sizeof(col_name), stdin);
    col_name[strcspn(col_name, "\n")] = '\0'; // Remove trailing newline character

    COLUMN* new_column = create_column(col_name);
    if (new_column == NULL) {
        printf("Failed to create shelf.\n");
        return;
    }

    if (add_column(df, new_column)) {
        printf("Shelf '%s' added successfully to the inventory.\n", col_name);
    } else {
        printf("Failed to add shelf to the dataframe.\n");
        delete_column(&new_column); // Free memory allocated for the column
    }
}



void addArticle(CDataframe* df) {
    char col_title[256];
    printf("Enter the title of the shelf where you want to add the article: ");
    scanf("%s", col_title);

    int found = 0;
    for (int i = 0; i < df->logical_size; i++) {
        if (strcmp(df->columns[i]->title, col_title) == 0) {
            // Ask for article details
            Article new_article;
            char article_name[256];

            printf("Enter the name of the article: ");
            scanf("%s", article_name);
            new_article.name = strdup(article_name);

            printf("Enter the price of the article: ");
            scanf("%d", &new_article.price);

            printf("Enter the quantity of the article: ");
            scanf("%d", &new_article.quantity);

            printf("Enter the reduction of the article: ");
            scanf("%d", &new_article.reduction);

            if (insert_article(df->columns[i], new_article)) {
                printf("Article added successfully to shelf '%s'.\n", col_title);
            } else {
                printf("Failed to add article to shelf '%s'.\n", col_title);
                free(new_article.name); // Free allocated memory if insertion fails
            }
            found = 1;
            break;
        }
    }
}

void deleteArticle(CDataframe* df) {
    char col_title[256];
    printf("Enter the title of the shelf from which you want to delete the article: ");
    scanf("%s", col_title);


    int found = 0;
    for (int i = 0; i < df->logical_size; i++) {
        if (strcmp(df->columns[i]->title, col_title) == 0) {

            int index;
            printf("Enter the index of the article you want to delete: ");
            scanf("%d", &index);


            delete_article(df->columns[i], index);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Shelf with title '%s' not found in the inventory.\n", col_title);
    }
}



void delete_dataframe(CDataframe** df) {
    if (df != NULL && *df != NULL) {
        for (int i = 0; i < (*df)->logical_size; i++) {
            delete_column(&((*df)->columns[i]));
        }
        free((*df)->columns);
        free(*df);
        *df = NULL;
    }
}

void print_dataframe(CDataframe* df) {
    printf("Printing the whole inventory:\n");
    for (int i = 0; i < df->logical_size; i++) {
        printf("Shelf %d: %s\n", i, df->columns[i]->title);
        for (int j = 0; j < df->columns[i]->logical_size; j++) {
            printf("[%d] Name: %s, Price: %d, Quantity: %d, Reduction: %d\n", j, df->columns[i]->data[j].name,
                   df->columns[i]->data[j].price, df->columns[i]->data[j].quantity, df->columns[i]->data[j].reduction);
        }
        printf("\n");
    }
}

void update_article_in_dataframe(CDataframe* df) {
    if (df == NULL || df->logical_size == 0) {
        printf("Inventory is empty or not initialized.\n");
        return;
    }

    printf("Enter the index of the shelf you want to update an article in: ");
    int col_index;
    scanf("%d", &col_index);

    if (col_index < 0 || col_index >= df->logical_size) {
        printf("Invalid shelf index!\n");
        return;
    }

    update_article(df->columns[col_index]);
}

COLUMN* reduction_shelf(CDataframe* df) {
    COLUMN* reduced_col = create_column("Articles with Reduction");
    for (int i = 0; i < df->logical_size; i++) {
        COLUMN* current_col = df->columns[i];
        for (int j = 0; j < current_col->logical_size; j++) {
            if (current_col->data[j].reduction >= 0) {
                insert_article(reduced_col, current_col->data[j]);
            }
        }
    }
    return reduced_col;
}

void searchArticle_inDf(CDataframe* df) {
    if (df == NULL || df->logical_size == 0) {
        printf("Inventory is empty or not initialized.\n");
        return;
    }

    char article_name[256];
    printf("Enter the name of the article you are searching for: ");
    scanf("%s", article_name);

    int found = 0;

    for (int i = 0; i < df->logical_size; i++) {
        COLUMN* current_col = df->columns[i];

        for (int j = 0; j < current_col->logical_size; j++) {
            if (strcmp(current_col->data[j].name, article_name) == 0) {
                printf("Article found in shelf: %s\n", current_col->title);
                printf("Index: %d, Name: %s, Price: %d, Quantity: %d, Reduction: %d\n",
                       j, current_col->data[j].name, current_col->data[j].price,
                       current_col->data[j].quantity, current_col->data[j].reduction);
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    if (!found) {
        printf("No article found with the name '%s'\n", article_name);
    }
}



COLUMN* ColumnCart(char* name) {
    COLUMN* cart_column = create_column(name);
    if (cart_column == NULL) {
        fprintf(stderr, "Failed to create shopping cart column\n");
        return NULL;
    }
    return cart_column;
}

void addItem(CDataframe* df, COLUMN* cart) {
    // Ask for the name of the column
    char col_name[256];
    printf("Enter the name of the column: ");
    scanf("%s", col_name);

    // Search for the column in the dataframe
    int col_found = 0;
    COLUMN* target_column = NULL;
    for (int i = 0; i < df->logical_size; i++) {
        if (strcmp(df->columns[i]->title, col_name) == 0) {
            target_column = df->columns[i];
            col_found = 1;
            break;
        }
    }

    // If column not found, return with a message
    if (!col_found) {
        printf("Column with name '%s' not found in the inventory.\n", col_name);
        return;
    }

    // Ask for the name of the article
    char article_name[256];
    printf("Enter the name of the article you want to add: ");
    scanf("%s", article_name);

    // Search for the article in the target column
    int article_found = 0;
    int article_index = -1;
    for (int i = 0; i < target_column->logical_size; i++) {
        if (strcmp(target_column->data[i].name, article_name) == 0) {
            article_index = i;
            article_found = 1;
            break;
        }
    }
    if (!article_found) {
        printf("Article with name '%s' not found in the column '%s'.\n", article_name, col_name);
        return;
    }

    Article new_article = target_column->data[article_index];
    if (!insert_article(cart, new_article)) {
        printf("Failed to add article to the cart.\n");
        return;
    }
    target_column->data[article_index].quantity--;
    if (target_column->data[article_index].quantity == 0) {
        delete_article(target_column, article_index);
        printf("Article '%s' removed from column '%s' because it's out of stock.\n", article_name, col_name);
    }

    printf("Article '%s' added to the cart.\n", article_name);
}

void deleteItem(COLUMN* cart) {
    char article_name[256];
    printf("Enter the name of the article you want to delete from the cart: ");
    scanf("%s", article_name);

    int article_found = 0;
    int article_index = -1;
    for (int i = 0; i < cart->logical_size; i++) {
        if (strcmp(cart->data[i].name, article_name) == 0) {
            article_index = i;
            article_found = 1;
            break;
        }
    }
    if (!article_found) {
        printf("Article with name '%s' not found in the cart.\n", article_name);
        return;
    }

    delete_article(cart, article_index);
    printf("Article '%s' deleted from the cart.\n", article_name);
}

void receipt(COLUMN* cart) {
    if (cart->logical_size == 0) {
        printf("The cart is empty.\n");
        return;
    }
    printf("\n\n*************** RECEIPT of the Shop ***************\n\n");
    printf("%-20s %-10s\n", "Article", "Price");
    int total_price = 0;
    for (int i = 0; i < cart->logical_size; i++) {
        printf("%-20s $%-10d\n", cart->data[i].name, cart->data[i].price);
        total_price += cart->data[i].price;
    }
    printf("\n%-20s $%-10d\n", "Total:", total_price);
    printf("\n*************** give us a good grade plzzzz ***************\n\n");
}
