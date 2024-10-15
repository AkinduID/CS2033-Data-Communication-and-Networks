// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // stdlib includes malloc() and free()

// user-defined header files
#include "chain.h"

// function prototypes
void print_chain(chain * chn); 
void run(chain * chn);


int main()
{
    chain * chn = (chain *) malloc(sizeof(chain));
    chn->head = NULL;
	run(chn);
    print_chain(chn);
    free(chn);
	return 0;
}

// parse the input
void run(chain *chn) 
{
	int num_rows;
    scanf("%d", &num_rows);
    getchar();

    int **matrix = (int **)malloc(num_rows * sizeof(int *));
    for (int i = 0; i < num_rows; i++) {
        matrix[i] = (int *)malloc(sizeof(int));
    }

    printf("Enter %d digits for the first row: ", num_rows);
    for (int i = 0; i < num_rows; i++) {
        int value = getchar() - '0';  // Convert character to integer
        matrix[i][0] = value;
    }
}

//Print the chain
void print_chain(chain * chn)
{
   node *current=chn->head;
   while(current!=NULL)
   {
       print_matrix(current->mat);
       current=current->next;
   }

}

void print_matrix(matrix * mat)
{
    for (int i = 0; i < mat->num_rows; i++)
    {
        for (int j = 0; j < mat->num_cols; j++)
        {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

