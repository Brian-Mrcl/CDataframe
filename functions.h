//
// Created by brian on 16/05/2024.
//

#ifndef CDATAFRAME_FUNCTIONS_H
#define CDATAFRAME_FUNCTIONS_H

#endif //CDATAFRAME_FUNCTIONS_H

typedef struct Article {
    char *name;     // Nom de l'article
    int price;      // Prix de l'article
    int quantity;   // Nombre d'articles disponibles
    int reduction;  // Réduction sur le prix de l'article
} Article;

typedef struct COLUMN {
    char *title;
    Article *data;
    int physical_size;
    int logical_size;
} COLUMN;

int insert_article(COLUMN *col, Article article);
void delete_article(COLUMN *col, int index);
void print_col(COLUMN *col);
void delete_column(COLUMN **col);
void price_under_n(COLUMN *col,int n);
void Reduc_catalog(COLUMN *col);
void search_by_name(COLUMN *col, const char *name);
void update_article(COLUMN *col);