#ifndef DATAFRAME_H
#define DATAFRAME_H

#include "Column.h"

typedef struct {
    COLUMN **columns;
    int physical_size;
    int logical_size;
} CDataframe;

CDataframe* create_dataframe();
int add_column(CDataframe* df, COLUMN* col);
void add_shelf(CDataframe* df);
void addArticle(CDataframe* df);
void deleteArticle(CDataframe* df);
void delete_dataframe(CDataframe** df);
void print_dataframe(CDataframe* df);
void update_article_in_dataframe(CDataframe* df);
COLUMN* reduction_shelf(CDataframe* df);
void searchArticle_inDf(CDataframe* df);
COLUMN* ColumnCart(char* name);
void addItem(CDataframe* df, COLUMN* cart);
void deleteItem(COLUMN* cart);
void receipt(COLUMN* cart);

#endif /* DATAFRAME_H */