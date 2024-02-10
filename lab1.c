#include <stdio.h>
#include <math.h>

int main() {
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);
  printf("%lf, %lf", (-b + sqrt(b*b - 4*a*c))/(2*a), (-b - sqrt(b*b - 4*a*c))/(2*a));
  return 0;
}
