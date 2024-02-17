#include <stdio.h>
#include <malloc.h>

void printmatrix(double** matrix, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%lf ", matrix[i][j]);
    }
    printf("\n");
  }
}

double** sum(double** matrix1, double** matrix2, int n) {
  
  double** res = (double**)malloc(sizeof(double*) * n);
  for (int i = 0; i < n; i++) {
    res[i] = (double*)malloc(sizeof(double) * n);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  
  return res;
}

double** minus(double** matrix1, double** matrix2, int n) {

  double** res = (double**)malloc(sizeof(double*) * n);
  for (int i = 0; i < n; i++) {
    res[i] = (double*)malloc(sizeof(double) * n);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }

  return res;
}

double** multiply(double** matrix1, double** matrix2, int n) {

  double** res = (double**)malloc(sizeof(double*) * n);
  for (int i = 0; i < n; i++) {
    res[i] = (double*)malloc(sizeof(double) * n);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++)
      res[i][j] += matrix1[i][k] - matrix2[k][j];
    }
  }

  return res;
}

int main(void) {
  int n;
  scanf("%d", &n);

  double** matrix1 = (double**)malloc(sizeof(double*)*n);
  for (int i = 0; i < n; i++) {
    matrix1[i] = (double*)malloc(sizeof(double)*n);
  }

  double** matrix2 = (double**)malloc(sizeof(double*)*n);
  for (int i = 0; i < n; i++) {
    matrix2[i] = (double*)malloc(sizeof(double)*n);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("Enter matrix1[%d][%d]: ", i, j);
      scanf("%lf", &matrix1[i][j]);
      printf("\n");
    }
  }

  printf("matrix1:\n");
  printmatrix(matrix1, n);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("Enter matrix2[%d][%d]: ", i, j);
      scanf("%lf", &matrix2[i][j]);
      printf("\n");
    }
  }

  printf("matrix2:\n");

  printmatrix(matrix2, n);

  printf("+ - summ matrices\n- - minus matrices\n* - multiply matrices");

  char operation;
  
  while (getchar() != '\n')
    continue;
  scanf("%c", &operation);
  
  double** res = (double**)malloc(sizeof(double*) * n);
  for (int i = 0; i < n; i++) {
    res[i] = (double*)malloc(sizeof(double) * n);
  }
  
  switch(operation) {
    case ('+'): res = sum(matrix1, matrix2, n);
    case ('-'): res = minus(matrix1, matrix2, n);
    case ('*'): res = multiply(matrix1, matrix2, n);
  }
  
    printmatrix(res, n); 
    
  return 0;
}