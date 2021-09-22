#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

#define MAX_SIZE 300

int main()
{
  char *userInput = malloc(MAX_SIZE * sizeof(char));
  while(*userInput != 'q')
    {
      printf("Please enter the item to tokenize:(Enter q to exit)\n");
      printf("$ ");
      fgets(userInput, MAX_SIZE, stdin);
      char **tokenized = malloc(MAX_SIZE * sizeof(char));
      tokenized = tokenize(userInput);
      printf("\n");
    }
  printf("Goodbye.\n");
}
