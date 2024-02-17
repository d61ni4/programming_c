#include <stdio.h>
#include <math.h>

//Написать функции, вычисляющие периметр и площадь треугольника по значениям длин трёх его сторон. Разместить их в отдельном модуле (отличном от того, где располагается функция main( )). Ввести с консоли значения длин сторон треугольника (с проверкой на корректность неравенства треугольника) и выдать на консоль вычисленные с помощью 
void error() {
  printf("Wrong parameters\n");
}

int perimeter(int a, int b, int с) {
  if ((a + b < с) || (a + с < b) || (b + с < a)) {
    error();
    return -1;
  }
  return a+b+с;
}

int square(int a, int b, int с) {
  if ((a + b < с) || (a + с < b) || (b + с < a)) {
    error();
    return -1;
  }
  float poluperimeter = perimeter(a, b, с) / 2;
  return sqrt(poluperimeter * (poluperimeter - a) * (poluperimeter - b) * (poluperimeter - с));
}

int main(void) {
  int a, b, c;
  printf("Enter a, b, c:\n");
  scanf("%d %d %d", &a, &b, &c);
  printf("perimmeter: %d, square %d", perimeter(a, b, c), square(a, b, c));
  return 0;
}