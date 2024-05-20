#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dataframe.h"

CDataframe* create_dataframe() {
    CDataframe* df = (CDataframe*) malloc(sizeof(CDataframe));
    if (df == NULL) {
        fprintf(stderr, "Failed to allocate memory for dataframe\n");
        return NULL;
    }
    df->columns = NULL;
    df->physical_size = 0;
    df->logical_size = 0;
    return df;
}

int add_column(CDataframe* df, COLUMN* col) {
    if (df->logical_size == df->physical_size) {
        df->physical_size = (df->physical_size == 0);
        COLUMN **new_columns = (COLUMN**) realloc(df->columns, sizeof(COLUMN*) * df->physical_size);
        if (new_columns == NULL) {
            return 0;
        }
        df->columns = new_columns;
    }
    df->columns[df->logical_size] = col;
    df->logical_size++;
    return 1;
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


void input_values_for_column(CDataframe *df) {
    int column_index;
    printf("Enter the index of the column to insert values into: ");
    scanf("%d", &column_index);

    // Check if the column index is valid
    if (column_index < 0 || column_index >= df->logical_size) {
        printf("Invalid column index.\n");
        return;
    }

    int num_values;
    printf("Enter the number of values you want to insert into column %d: ", column_index);
    scanf("%d", &num_values);

    int value;
    for (int i = 0; i < num_values; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        if (!insert_value(df->columns[column_index], value)) {
            printf("Failed to insert value.\n");
            return;
        }
    }
    printf("Values successfully inserted into column %d.\n", column_index);
}
void PrintCdataFrame(CDataframe *df) {
    if (df == NULL) {
        printf("No dataframe exists.\n");
        return;
    }

    int choice;
    printf("Enter the number corresponding to the action you want to perform:\n");
    printf("1. Print the whole dataframe.\n");
    printf("2. Print columns within a range.\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Printing the whole dataframe:\n");
            for (int i = 0; i < df->logical_size; i++) {
                printf("Column %d: %s\n", i, df->columns[i]->title);
                print_col(df->columns[i]);
            }
            break;
        case 2:
            int start_index, end_index;
            printf("Enter the start index of the range: ");
            scanf("%d", &start_index);
            printf("Enter the end index of the range: ");
            scanf("%d", &end_index);

            if (start_index < 0 || start_index >= df->logical_size || end_index < start_index || end_index >= df->logical_size) {
                printf("Invalid range.\n");
                return;
            }

            printf("Printing columns from index %d to index %d:\n", start_index, end_index);
            for (int i = start_index; i <= end_index; i++) {
                printf("Column %d: %s\n", i, df->columns[i]->title);
                print_col(df->columns[i]);
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
}


void delete_values_from_column(CDataframe *df) {
    printf("The dataframe contains %d columns.\n", df->logical_size);
    for (int i = 0; i < df->logical_size; i++) {
        printf("Column %d: %s\n", i, df->columns[i]->title);
    }

    int column_index;
    printf("Enter the index of the column to delete values from: ");
    scanf("%d", &column_index);


    if (column_index < 0 || column_index >= df->logical_size) {
        printf("Invalid column index.\n");
        return;
    }

    int num_values;
    printf("Enter the number of values you want to delete from column %d: ", column_index);
    scanf("%d", &num_values);

    COLUMN *col = df->columns[column_index];


    if (num_values <= 0 || num_values > col->logical_size) {
        printf("Invalid number of values to delete.\n");
        return;
    }

    col->logical_size -= num_values;

    printf("Successfully deleted %d values from column %d.\n", num_values, column_index);
}


void add_columns_to_dataframe(CDataframe* df) {
    int num_columns;
    printf("Enter the number of columns to add: ");
    scanf("%d", &num_columns);

    for (int i = 0; i < num_columns; i++) {
        char title[100];
        printf("Enter the name for column %d: ", i + 1);
        scanf("%s", title);

        COLUMN* new_column = create_column(title);
        if (new_column == NULL) {
            printf("Failed to create column.\n");
            return;
        }

        // Optionally, you can prompt the user to input values for the new column here

        if (!add_column(df, new_column)) {
            printf("Failed to add column to dataframe.\n");
            delete_column(&new_column);
            return;
        }

        printf("Column '%s' added to dataframe successfully.\n", title);
    }
}

void analyze_cdataframe(CDataframe *df) {
    if (df == NULL) {
        printf("No dataframe exists.\n");
        return;
    }

    int choice;
    printf("Enter the number corresponding to the action you want to perform:\n");
    printf("1. Display the number of columns in the CDataframe.\n");
    printf("2. Display the number of values in a column.\n");
    printf("3. Print the names of columns with a specific value.\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Number of columns in the CDataframe: %d\n", df->logical_size);
            break;

        case 2:
            int column_index;
            printf("Enter the index of the column to analyze: ");
            scanf("%d", &column_index);
            if (column_index < 0 || column_index >= df->logical_size) {
                printf("Invalid column index.\n");
                return;
            }
            printf("Number of values in column %d: %d\n", column_index, df->columns[column_index]->logical_size);
            break;

        case 3:
            int value_to_search;
            printf("Enter the value to search for: ");
            scanf("%d", &value_to_search);
            printf("Columns containing the value %d:\n", value_to_search);
            for (int i = 0; i < df->logical_size; i++) {
                COLUMN *col = df->columns[i];
                for (int j = 0; j < col->logical_size; j++) {
                    if (col->data[j] == value_to_search) {
                        printf("%s\n", col->title);
                        break;
                    }
                }
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
}


void TestingFunctionsCdataFrame() {

    CDataframe* df = create_dataframe();
    if (df == NULL) {
        printf("Failed to create dataframe.\n");
        return;
    }

    printf("             Welcome in the first part of the C project of Brian Marcel and Boumedine Rayan \n");
    printf("First of all, we will present you the part 1 of the project we were working on without any real applications \n");
    printf("Feel free to check the code and dont forget to check our real world application ( I worked hard on it please watch it )\n\n\n");

    add_columns_to_dataframe(df);


    input_values_for_column(df);

    PrintCdataFrame(df);

    delete_values_from_column(df);

    analyze_cdataframe(df);

    delete_dataframe(&df);
}