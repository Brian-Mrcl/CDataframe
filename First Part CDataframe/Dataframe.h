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
void delete_dataframe(CDataframe** df);
void input_values_for_column(CDataframe *df);
void PrintCdataFrame(CDataframe *df);
void delete_values_from_column(CDataframe *df);
void add_columns_to_dataframe(CDataframe* df);
void analyze_cdataframe(CDataframe *df);
void TestingFunctionsCdataFrame();
#endif /* DATAFRAME_H */