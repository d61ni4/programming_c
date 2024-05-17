//Создать текстовый файл с записями, включающие имя/фамилию человека, год рожде-ния, пол и рост (в метрах). Упорядочить элементы по году рождения, имени/фамилии, полу или росту. Вывести результат. Указать элемент, по которому следует упорядочить, через консоль. А также реализовать возможность задавать несколько полей для упоря-дочивания.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char firstName[20];
  char lastName[20];
  char sex;
  float height;
  unsigned int year;
} human;

int main(void) {

  FILE *input = fopen("inputPeople.txt", "r");
  FILE *output = fopen("outputPeople.txt", "w");
  if (input == NULL) {
    printf("Error\n");
    return 1;
  }
  int n;
  fscanf(input, "%d", &n);
  human humen[n];
  
  for (int i = 0; i < n; i++) {
    fscanf(input, "%s %s %c %u %f", humen[i].firstName, humen[i].lastName, &humen[i].sex, &humen[i].year, &humen[i].height);
  }
  
  fclose(input);
  
  char sortParameter;
  printf("Enter the parameter for sorting (F for First Name, L for Last Name, S for Sex, H for Height, Y for Year): ");
  scanf("%c", &sortParameter);
  
  human humenSorted[n];
  for (int i = 0; i < n; i++) {
    humenSorted[i] = humen[i];
  }

  if (sortParameter == 'F') {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - 1; j++) {
        if (strcmp(humenSorted[j].firstName, humenSorted[j + 1].firstName) > 0) {
          human temp = humenSorted[j];
          humenSorted[j] = humenSorted[j + 1];
          humenSorted[j + 1] = temp;
        }
      }
    }     
  } else if (sortParameter == 'L') {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - 1; j++) {
        if (strcmp(humenSorted[j].lastName, humenSorted[j + 1].lastName) > 0) {
          human temp = humenSorted[j];
          humenSorted[j] = humenSorted[j + 1];
          humenSorted[j + 1] = temp;
        }
      }
    }
  } else if (sortParameter == 'S') {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - 1; j++) {
        if (humenSorted[j].sex > humenSorted[j + 1].sex) {
          human temp = humenSorted[j];
          humenSorted[j] = humenSorted[j + 1];
          humenSorted[j + 1] = temp;
        }
      }
    }
  } else if (sortParameter == 'H') {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - 1; j++) {
        if (humenSorted[j].height > humenSorted[j + 1].height) {
          human temp = humenSorted[j];
          humenSorted[j] = humenSorted[j + 1];
          humenSorted[j + 1] = temp;
        }
      }
    }
  } else if (sortParameter == 'Y') {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - 1; j++) {
        if (humenSorted[j].year > humenSorted[j + 1].year) {
          human temp = humenSorted[j];
          humenSorted[j] = humenSorted[j + 1];
          humenSorted[j + 1] = temp;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    fprintf(output, "%s %s %c %u %f\n", humenSorted[i].firstName, humenSorted[i].lastName,
      humenSorted[i].sex, humenSorted[i].year, humenSorted[i].height);
  }

  return 0;
}