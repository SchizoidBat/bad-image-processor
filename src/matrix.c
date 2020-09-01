#include "matrix.h"
#include <stdlib.h>

int matrixalloc(matrix *X)
{
  if(X == NULL) return 1;
  
  int rows = X->rows;
  int cols = X->cols;
  X->R = malloc(sizeof(int*)*rows);
  X->G = malloc(sizeof(int*)*rows);
  X->B = malloc(sizeof(int*)*rows);
  
  for(int i = 0; i<rows; i++)
  {
    X->R[i] = malloc(sizeof(int)*cols);
    X->G[i] = malloc(sizeof(int)*cols);
    X->B[i] = malloc(sizeof(int)*cols);
  }
  return 0;
}

void freematrix(matrix *X)
{
  for(int i = 0; i<X->rows; i++)
  {
    free(X->R[i]);
    free(X->G[i]);
    free(X->B[i]);
  }
  free(X->R);
  free(X->G);
  free(X->B);
  free(X);
}