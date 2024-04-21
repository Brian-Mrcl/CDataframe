# Column Data Structure in C

## Team members
- **Rayan BOUMEDINE**
- **Brian Marcel**

## GitHub Repository: 
[![github](https://img.shields.io/badge/Project's_link-black?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Pandarock0/CDataframe)

## Project Description:

Our project aims to implement a columnar data management system in C, providing functionalities to create, manipulate, and analyze tabular data efficiently. The core components of our project include:
1. column.h: Contains the structure and function prototypes for managing a single column of data.
2. cdataframe.h: Contains the structure and function prototypes for managing a collection of columns, forming a CDataframe.
3. main.c: Provides an example scenario demonstrating the usage of the implemented functions.

## Features

- Creation of a column with a title
- Insertion of values into the column
- Printing the data stored in the column
- Counting occurrences of a specific value in the column
- Retrieving the value at a given index in the column
- Counting the number of values greater than a given value in the column
- Counting the number of values less than a given value in the column
- Counting the number of values equal to a given value in the column

## Note

- The program dynamically allocates memory for the column data and reallocates as needed to accommodate more values.
- Make sure to delete the column before exiting to avoid memory leaks.

## Installation 
Run the given command to install the project:

```bash
  git clone https://github.com/Pandarock0/CDataframe
```
