#include <stdio.h>
#include <stdlib.h> // includes malloc(), free(), realloc()
#include <string.h> // includes memcpy()

#include "chain.h" // do not modify this file
#include <math.h>

// put your function prototypes for additional helper functions below:


// implementation
matrix *create_matrix(int num_rows, int num_cols)
{   
    // TODO
    matrix* newMatrix = (matrix*)malloc(sizeof(matrix));
    newMatrix->num_rows = num_rows;
    newMatrix->num_cols = num_cols;
    newMatrix->data = (int**)malloc(sizeof(int*)*num_rows);
    for(int i=0;i<num_rows;i++){
        newMatrix->data[i] = (int*)malloc(sizeof(int)*num_cols);
    }
    return newMatrix;
}

void add_row(matrix *mat, int *row)
{
    // TODO
    if (mat->num_rows == 0) {
        return; // Matrix has no rows
    }

    // Resize the data array to accommodate the new row
    mat->data = (int**)realloc(mat->data, (mat->num_rows + 1) * sizeof(int*));
    mat->data[mat->num_rows] = row;
    mat->num_rows++;
}

void add_col(matrix *mat, int *col)
{
    // TODO
    if (mat->num_cols == 0) {
        return; // Matrix has no columns
    }

    // Resize each row to accommodate the new column
    for (int i = 0; i < mat->num_rows; i++) {
        mat->data[i] = (int*)realloc(mat->data[i], (mat->num_cols + 1) * sizeof(int));
        mat->data[i][mat->num_cols] = col[i];
    }
    mat->num_cols++;
}

void increment(matrix *mat, int num)
{
    // TODO
    for (int i = 0; i < mat->num_rows; i++) {
        for (int j = 0; j < mat->num_cols; j++) {
            mat->data[i][j] += num;
        }
    }
}

void scalar_multiply(matrix *mat, int num)
{
    // TODO
    for(int i=0;i<mat->num_rows;i++){
        for(int j=0;j<mat->num_cols;j++){
            mat->data[i][j] = mat->data[i][j] * num;
        }
    }
}

void scalar_divide(matrix *mat, int num)
{
    // TODO
    for(int i=0;i<mat->num_rows;i++){
        for(int j=0;j<mat->num_cols;j++){
            mat->data[i][j] = mat->data[i][j] / num;
        }
    }
}

void scalar_power(matrix *mat, int num)
{
    // TODO
    for(int i=0;i<mat->num_rows;i++){
        for(int j=0;j<mat->num_cols;j++){
            mat->data[i][j] = pow(mat->data[i][j],num);
        }
    }
}

void delete_matrix(matrix *mat)
{
    // TODO
    for(int i=0;i<mat->num_rows;i++){
        for(int j=0;j<mat->num_cols;j++){
            free(mat->data[i][j]);
        }
    }
}


/*
    DO NOT MODIFY BELOW
*/
// print out matrix in row-major order
// elements in the same row are space-separated
// each row starts in a new line
void print_matrix(matrix *mat) 
{
    int row_idx, col_idx;
    for(row_idx = 0; row_idx < mat->num_rows; ++row_idx) {
        for(col_idx = 0; col_idx < mat->num_cols; ++col_idx) {
            if (col_idx == mat->num_cols-1) {
                printf("%d\n", mat->data[row_idx][col_idx]);
            } else {
                printf("%d ", mat->data[row_idx][col_idx]);
            }
        }
    }
}

//Add the rest of the functions needed for the chain below
