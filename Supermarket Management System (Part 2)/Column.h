#ifndef COLUMN_H
#define COLUMN_H

typedef struct Article {
    char *name;
    int price;
    int quantity;
    int reduction;
} Article;

typedef struct COLUMN {
    char *title;
    Article *data;
    int physical_size;
    int logical_size;
} COLUMN;

COLUMN* create_column(char* title);
int insert_article(COLUMN *col, Article article);
void delete_article(COLUMN *col, int index);
void print_col(COLUMN *col);
void delete_column(COLUMN **col);
void price_under_n(COLUMN *col,int n);
void Reduc_catalog(COLUMN *col);
void search_by_name(COLUMN *col, const char *name);
void update_article(COLUMN *col);

#endif /* COLUMN_H */