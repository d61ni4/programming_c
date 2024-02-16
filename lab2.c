#include <stdio.h>

int main(void) {
  int N;
  double mainsum = 0, secsum = 0, sum = 0;
  
  printf("Enter matrix size: \n");
  scanf("%d\n", &N);
  
  double matrix[N][N];
 
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("Enter [%d][%d] element: \n", i, j);
      scanf("%lf", &matrix[i][j]);
    }
  }

  printf("matrix: \n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%lf ", matrix[i][j]);
    }
    printf("\n");
  }
  
  for (int i = 0; i < N; i++) {
    mainsum += matrix[i][i];
    secsum += matrix[i][N-i];
  }
  
  printf("main sum: %lf, secondary sum: %lf\n", mainsum, secsum);
  
  printf("kvadrat\n");
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        sum += matrix[i][k] * matrix[k][j];
      }
      printf("%lf ", sum);
      sum = 0;
    }
  printf("\n");
  }
  
  return 0;
}