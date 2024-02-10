#include <stdio.h>
#include <math.h>

int main() {
  double a, b, c, D;
  scanf("%lf %lf %lf", &a, &b, &c);
  D = b*b - 4*a*c;
  
  if (D > 0) {
    printf("two roots: %lf, %lf", (-b + sqrt(D))/(2*a), (-b - sqrt(D))/(2*a));
  } else if (D == 0) {
    printf("one root: %lf", -b/(2*a));
  } else {
    printf("no solution");
  }

  return 0;
}
