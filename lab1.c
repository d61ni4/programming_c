#include <stdio.h>
#include <math.h>

int main() {
  double a, b, c, D;
  int repeat = 1;
  
  while (repeat) {
    printf("enter a, b, c\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    D = b*b - 4*a*c;

    if (D > 0) {
      printf("two roots: %lf, %lf\n", (-b + sqrt(D))/(2*a), (-b - sqrt(D))/(2*a));
    } else if (D == 0) {
      printf("one root: %lf\n", -b/(2*a));
    } else {
      printf("no solution\n");
    }
    printf("repeat? 1 - yes, 0 - no\n");
    
    scanf("%d", &repeat);
  }
  
  return 0;
}
