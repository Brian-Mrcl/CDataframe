#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CDataFrame.h"


int main() {
    COLUMN *mycol = NULL;
    COLUMN *current_col = NULL;

    int choice;
    int value, index;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (mycol != NULL) {
                    printf("Column already exists. Deleting previous column...\n");
                    delete_column(&mycol);
                }
                printf("Enter column title: ");
                char title[100];
                scanf("%s", title);
                mycol = create_column(title);
                current_col = mycol;
                break;
            case 2:
                if (current_col == NULL) {
                    printf("No column created yet.\n");
                    break;
                }
                printf("Enter value to insert: ");
                scanf("%d", &value);
                if (insert_value(current_col, value))
                    printf("Value added successfully to the column\n");
                else
                    printf("Error adding value to the column\n");
                break;
            case 3:
                if (current_col == NULL) {
                    printf("No column created yet.\n");
                    break;
                }
                print_col(current_col);
                break;
            case 4:
                if (current_col == NULL) {
                    printf("No column created yet.\n");
                    break;
                }
                printf("Enter value to count occurrences: ");
                scanf("%d", &value);
                printf("Number of occurrences: %d\n", count_occurrences(current_col, value));
                break;
            case 5:
                if (current_col == NULL) {
                    printf("No column created yet.\n");
                    break;
                }
                printf("Enter index to get value: ");
                scanf("%d", &index);
                printf("Value at index %d: %d\n", index, get_value(current_col, index));
                break;
            case 6:
                if (current_col == NULL) {
                    printf("No column created yet.\n");
                    break;
                }
                printf("Enter value to count values greater than: ");
                scanf("%d", &value);
                printf("Number of values greater than %d: %d\n", value, retgreater(current_col, value));
                break;
            case 7:
                if (current_col == NULL) {
                    printf("No column created yet.\n");
                    break;
                }
                printf("Enter value to count values less than: ");
                scanf("%d", &value);
                printf("Number of values less than %d: %d\n", value, retless(current_col, value));
                break;
            case 8:
                if (current_col == NULL) {
                    printf("No column created yet.\n");
                    break;
                }
                printf("Enter value to count occurrences: ");
                scanf("%d", &value);
                printf("Number of values equal to %d: %d\n", value, count_values_equal_to(current_col, value));
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    if (mycol != NULL) {
        delete_column(&mycol);
    }

    return 0;
}