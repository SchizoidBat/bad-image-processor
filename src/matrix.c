#include "matrix.h"
#include <stdlib.h>

matrix emptyMatrixStruct() //allocates space for a matrix struct and returns pointer to it.
{
  matrix res = malloc(sizeof(struct matrix));
  return res;
}

int matrixalloc(matrix X)
{
  if(X == NULL) return 1;
  
  int rows = X->rows;
  int cols = X->cols;
  X->mat = malloc(sizeof(float*)*rows);
  for(int i = 0; i<rows; i++)
  {
    X->mat[i] = malloc(sizeof(float)*cols);
  }
  return 0;
}

matrix creatematrix(int rows,int cols)
{
  matrix res = emptyMatrixStruct();
  res->rows = rows;
  res->cols = cols;
  if(matrixalloc(res) != 0) return NULL;
  return res;
}

void freematrix(matrix X)
{
  for(int i = 0; i<X->rows; i++)
    free(X->mat[i]);
  free(X->mat);
  free(X);
}
