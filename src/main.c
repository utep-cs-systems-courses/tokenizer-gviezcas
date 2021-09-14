#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define MAX_SIZE 300

int main()
{
  char *userInput = malloc(MAX_SIZE * sizeof(char));
  
  printf("Please enter the item to tokenize:\n");
  printf("$");
  fgets(userInput, MAX_SIZE, stdin);
  puts(userInput);
}
