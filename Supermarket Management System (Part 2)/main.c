//
// Created by brian on 06/05/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "Dataframe.h"


int main() {
    char userType;
    char password[20];
    CDataframe* df = create_dataframe();
    int isLoggedIn = 0;
    char Client[252] = "Client";
    COLUMN* cart = ColumnCart(Client);


    while (1) {
        printf("\n-------------------------------------------\n");
        printf("Welcome to the Supermarket Management System\n");
        printf("-------------------------------------------\n");
        printf("Are you a customer (C) or an employee (E)? ");
        scanf(" %c", &userType);

        if (userType == 'C' || userType == 'c') {
            printf("\n-------------- client menue --------------\n");
            printf("1. Search for an article in the inventory\n");
            printf("2. View articles with reductions\n");
            printf("3. Print your shopping cart\n");
            printf("4. Add item to shopping cart\n");
            printf("5. Delete item from shopping cart\n");
            printf("6. Print receipt\n");
            printf("7. Exit\n");
            printf("-------------------------------------------\n");

            int choice;
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    searchArticle_inDf(df);
                    break;
                case 2:
                    reduction_shelf(df);
                    break;
                case 3:
                    print_col(cart);
                    break;
                case 4:
                    addItem(df,cart);
                    break;
                case 5:
                    deleteItem(cart);
                    break;
                case 6:
                    receipt(cart);
                    break;
                case 7:
                    printf("Have a good day and thank you for your trust ...\n");
                    delete_dataframe(&df);
                    if (cart != NULL) {
                        delete_column(&cart);
                    }
                    return 0;
                default:
                    printf("Invalid choice! Please enter a number between 1 and 7.\n");
            }
        } else if (userType == 'E' || userType == 'e') {
            if (!isLoggedIn) {
                printf("\nPlease enter the employee password: ");
                scanf("%s", password);
                if (strcmp(password, "EFREIPROJECT") == 0) {
                    isLoggedIn = 1;
                    printf("Logged in as an employee.\n");
                } else {
                    printf("Incorrect password. Try again.\n");
                }
            } else {
                printf("\n-------------- Employee Menu --------------\n");
                printf("1. Update an article in the inventory\n");
                printf("2. Add an article in the inventory\n");
                printf("3. Delete an article in the inventory\n");
                printf("4. Update an article in the inventory\n");
                printf("5. View articles with reductions\n");
                printf("6. Search for an article in the inventory\n");
                printf("7. Print Inventory\n");
                printf("8. Add a shelf to the inventory\n");
                printf("9. Exit\n");
                printf("-------------------------------------------\n");

                int choice;
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        update_article_in_dataframe(df);
                        break;
                    case 2:
                        addArticle(df);
                        break;
                    case 3:
                        deleteArticle(df);
                        break;
                    case 4:
                        update_article_in_dataframe(df);
                        break;

                    case 5:
                        reduction_shelf(df);
                    case 6:
                        searchArticle_inDf(df);
                    case 7:
                        print_dataframe(df);
                        break;
                    case 8:
                        add_shelf(df);
                    case 9:
                        printf("Logging out...\n");
                        isLoggedIn = 0;
                        break;
                    default:
                        printf("Invalid choice! Please enter a number between 1 and 5.\n");
                }
            }
        } else {
            printf("\nInvalid user type! Please enter 'C' for Customer or 'E' for Employee.\n");
        }
    }

    return 0;
}
