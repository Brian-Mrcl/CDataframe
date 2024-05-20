Dataframe Project in C
Overview
This project demonstrates basic operations on a dataframe structure in C, including creation, manipulation, and analysis of columns and their values. The project includes three main components:

Column.h: Header file defining the structure and functions for managing individual columns.
Dataframe.c: Implementation file providing functions to create, manipulate, and analyze dataframes.
main.c: Main program file that tests the functionalities of the dataframe.
Files
Column.h: Defines the COLUMN structure and functions to create, insert values, delete, and perform other operations on columns.
Dataframe.c: Implements the CDataframe structure and provides functions to add columns, input values, print, delete values, and analyze the dataframe.
main.c: Contains the main function which tests the dataframe functionalities by calling the appropriate functions.
Getting Started
Prerequisites
To compile and run this project, you need a C compiler like gcc.

Compilation
Use the following command to compile the project:

sh
Copier le code
gcc -o dataframe main.c Dataframe.c -lm
This will generate an executable file named dataframe.

Running the Program
Run the executable with the following command:

sh
Copier le code
./dataframe
The program will prompt you to perform various operations on the dataframe, such as adding columns, inserting values, printing the dataframe, and analyzing the data.

Functionalities
Column.h
COLUMN: Structure representing a column with a title, data array, physical size, and logical size.
Functions:
create_column(char* title): Creates a new column.
insert_value(COLUMN *col, int value): Inserts a value into the column.
delete_column(COLUMN **col): Deletes a column.
print_col(COLUMN *col): Prints the values of a column.
count_occurrences(const COLUMN *col, int x): Counts occurrences of a value in the column.
get_value(COLUMN *col, int x): Gets a value from the column.
retgreater(COLUMN *col, int x): Returns the number of values greater than x in the column.
retless(COLUMN *col, int x): Returns the number of values less than x in the column.
count_values_equal_to(COLUMN *col, int x): Counts values equal to x in the column.
Dataframe.c
CDataframe: Structure representing a dataframe containing multiple columns.
Functions:
create_dataframe(): Creates a new dataframe.
add_column(CDataframe* df, COLUMN* col): Adds a column to the dataframe.
delete_dataframe(CDataframe** df): Deletes the dataframe.
input_values_for_column(CDataframe *df): Inputs values for a specific column.
PrintCdataFrame(CDataframe *df): Prints the dataframe or specified range of columns.
delete_values_from_column(CDataframe *df): Deletes values from a specific column.
add_columns_to_dataframe(CDataframe* df): Adds new columns to the dataframe.
analyze_cdataframe(CDataframe *df): Analyzes the dataframe for various metrics.
main.c
main(): Calls TestingFunctionsCdataFrame to demonstrate the functionalities of the dataframe, including creating, adding columns, inserting values, printing, deleting values, and analyzing the dataframe.
Authors
Brian Marcel
Boumedine Rayan
