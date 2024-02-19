#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  FILE *input = fopen("people.txt", "r");
  FILE *output = fopen("people1980.txt", "w");
  int n;
  fscanf(input, "%d", &n);
  
  char** inputlist = (char**)malloc(sizeof(char*)*(n+2));
  for (int i = 0; i < n + 2; i++) {
    inputlist[i] = (char*)malloc(sizeof(char)*64);
    fgets(inputlist[i], 64, input);
  }

  for (int i = 0; i < n + 2; i++) {
    int pointer = 0;
    while (!isdigit(inputlist[i][pointer])) {
      pointer++;
    }
    
    int year = atoi(inputlist[i]+pointer);
    if (year > 1980) {
      fputs(inputlist[i], output);
    }
    
  }
  return 0;
}