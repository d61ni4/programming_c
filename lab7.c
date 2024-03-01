//Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения. 
//Объявить два массива из четырёх элементов типа humen. Ввести с консоли или из файла элементы одного массива
// и построить на их основе другой, упорядочив элементы по го-дам рождения. Вывести результат

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char firstName[20];
  char lastName[20];
  int year;
} human;

int main(void) {
  
  human humen[4];
  human humenSorted[4];

  for (int i = 0; i < 4; i++) {
    printf("Enter first name for human %d: ", i+1);
    scanf("%s", humen[i].firstName);
    printf("Enter last name for human %d: ", i+1);
    scanf("%s", humen[i].lastName);
    printf("Enter year of birth for human %d: ", i+1);
    scanf("%d", &humen[i].year);
  }

  printf("Humen:\n");
  for (int i = 0; i < 4; i++) {
      printf("Human %d: %s %s, year of birth: %d\n", i+1, humen[i].firstName, humen[i].lastName, humen[i].year);
  }

  for (int i = 0; i < 4; i++) {
    humenSorted[i] = humen[i];
  }

  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      if (humenSorted[i].year > humenSorted[j].year) {
        human temp = humenSorted[i];
        humenSorted[i] = humenSorted[j];
        humenSorted[j] = temp;
      }
    }
  }

  printf("Sorted Humen:\n");
  for (int i = 0; i < 4; i++) {
    printf("Human %d: %s %s, year of birth: %d\n", i + 1, humenSorted[i].firstName, humenSorted[i].lastName, humenSorted[i].year);
  }
  
  return 0;
}