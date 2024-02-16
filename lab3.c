#include <stdio.h>
#include <string.h>

int main(void) {
  // Ввести с консоли строку символов произвольной длины (до 80 символов). Поме-нять в ней все маленькие символы ‘a’ и ‘b’ на заглавные и вывести на консоль получен-ную строку.

  
  char str[80];
  fgets(str, 80, stdin);
  printf("Your string: %s\n", str);
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == 'a') str[i] = 'A';
    if (str[i] == 'b') str[i] = 'B';
  }
  printf("Changed string: %s\n", str);
  return 0;
}