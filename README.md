## GitHub Repository: 
[![github](https://img.shields.io/badge/Project's_link-black?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Pandarock0/CDataframe)

# Dataframe Project in C (Part 1)

## Overview

This project demonstrates basic operations on a dataframe structure in C, including creation, manipulation, and analysis of columns and their values. The project includes three main components:

1. **Column.c**: File defining the structure and functions for managing individual columns.
2. **Dataframe.c**: Implementation file providing functions to create, manipulate, and analyze dataframes.
3. **main.c**: Main program file that tests the functionalities of the dataframe.

## Files

- **Column.c**: Defines the `COLUMN` structure and functions to create, insert values, delete, and perform other operations on columns.
- **Dataframe.c**: Implements the `CDataframe` structure and provides functions to add columns, input values, print, delete values, and analyze the dataframe.
- **main.c**: Contains the `main` function which tests the dataframe functionalities by calling the appropriate functions.

## Getting Started

### Prerequisites

To compile and run this project, you need a C compiler like Clion.

# Functionalities

## Column.c

**COLUMN**: Structure representing a column with a title, data array, physical size, and logical size.

### Functions:

- `create_column(char* title)`: Creates a new column.
- `insert_value(COLUMN *col, int value)`: Inserts a value into the column.
- `delete_column(COLUMN **col)`: Deletes a column.
- `print_col(COLUMN *col)`: Prints the values of a column.
- `count_occurrences(const COLUMN *col, int x)`: Counts occurrences of a value in the column.
- `get_value(COLUMN *col, int x)`: Gets a value from the column.
- `retgreater(COLUMN *col, int x)`: Returns the number of values greater than x in the column.
- `retless(COLUMN *col, int x)`: Returns the number of values less than x in the column.
- `count_values_equal_to(COLUMN *col, int x)`: Counts values equal to x in the column.

## Dataframe.c

**CDataframe**: Structure representing a dataframe containing multiple columns.

### Functions:

- `create_dataframe()`: Creates a new dataframe.
- `add_column(CDataframe* df, COLUMN* col)`: Adds a column to the dataframe.
- `delete_dataframe(CDataframe** df)`: Deletes the dataframe.
- `input_values_for_column(CDataframe *df)`: Inputs values for a specific column.
- `PrintCdataFrame(CDataframe *df)`: Prints the dataframe or specified range of columns.
- `delete_values_from_column(CDataframe *df)`: Deletes values from a specific column.
- `add_columns_to_dataframe(CDataframe* df)`: Adds new columns to the dataframe.
- `analyze_cdataframe(CDataframe *df)`: Analyzes the dataframe for various metrics.

## main.c

**main()**: Calls `TestingFunctionsCdataFrame` to demonstrate the functionalities of the dataframe, including creating, adding columns, inserting values, printing, deleting values, and analyzing the dataframe.

# CDataframe, Supermarket Management System in C (Part 2)

## Overview
This project demonstrates the management of a supermarket inventory using a C program. It includes the creation, manipulation, and analysis of shelves and their items. The project is composed of three main components:

1. `Column.c`: Defines the structure and functions for managing individual shelves (columns).
2. `Dataframe.c`: Provides functions to create, manipulate, and analyze a collection of shelves (dataframes).
3. `main.c`: Main program file that tests the functionalities of the supermarket management system.

## Files

- **Column.c**: Defines the `COLUMN` structure and functions to create, insert articles, delete, and perform other operations on shelves.
- **Dataframe.c**: Implements the `CDataframe` structure and provides functions to add shelves, input articles, print, delete articles, and analyze the inventory.
- **main.c**: Contains the main function which tests the supermarket management functionalities by calling the appropriate functions.

## Getting Started

### Prerequisites

To compile and run this project, you need a C compiler such as GCC.

## Functionalities

### Column.c

**COLUMN**: Structure representing a shelf with a title, an array of articles, physical size, and logical size.

**Functions**:

- `COLUMN* create_column(char* title)`: Creates a new shelf.
- `int insert_article(COLUMN *col, Article article)`: Inserts an article into the shelf.
- `void delete_article(COLUMN *col, int index)`: Deletes an article from the shelf.
- `void print_col(COLUMN *col)`: Prints the articles of a shelf.
- `void delete_column(COLUMN **col)`: Deletes a shelf.
- `void price_under_n(COLUMN *col, int n)`: Prints articles with a price under n.
- `void Reduc_catalog(COLUMN *col)`: Prints articles with a reduction.
- `void search_by_name(COLUMN *col, const char *name)`: Searches for an article by name.
- `void update_article(COLUMN *col)`: Updates an article in the shelf.

### Dataframe.c

**CDataframe**: Structure representing an inventory containing multiple shelves.

**Functions**:

- `CDataframe* create_dataframe()`: Creates a new inventory.
- `int add_column(CDataframe* df, COLUMN* col)`: Adds a shelf to the inventory.
- `void add_shelf(CDataframe* df)`: Prompts the user to add a new shelf.
- `void addArticle(CDataframe* df)`: Prompts the user to add an article to a shelf.
- `void deleteArticle(CDataframe* df)`: Prompts the user to delete an article from a shelf.
- `void delete_dataframe(CDataframe** df)`: Deletes the inventory.
- `void print_dataframe(CDataframe* df)`: Prints the entire inventory.
- `void update_article_in_dataframe(CDataframe* df)`: Prompts the user to update an article in the inventory.
- `COLUMN* reduction_shelf(CDataframe* df)`: Creates a shelf of articles with reductions.
- `void searchArticle_inDf(CDataframe* df)`: Searches for an article in the inventory.
- `COLUMN* ColumnCart(char* name)`: Creates a new shopping cart.
- `void addItem(CDataframe* df, COLUMN* cart)`: Adds an item to the shopping cart.

### main.c

**main()**: Calls various functions to demonstrate the functionalities of the supermarket management system, including creating shelves, adding articles, printing the inventory, deleting articles, and analyzing the inventory.

## Installation 
Run the given command to install the project:

```bash
  git clone https://github.com/Pandarock0/CDataframe
```

## Authors

- Brian Marcel
- Boumedine Rayan
