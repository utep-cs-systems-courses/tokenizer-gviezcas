#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

#define MAX_SIZE 300

int main()
{
  char *userInput = malloc(MAX_SIZE * sizeof(char));
  char **tokenized_string = malloc(MAX_SIZE * sizeof(char*));
  char **beginning = malloc(MAX_SIZE * sizeof(char*));
  beginning = tokenized_string;
  while(*userInput != 'q')
    {
	  printf("Please enter the item to tokenize:(Enter q to exit)\n");
	  printf("$ ");
	  fgets(userInput, MAX_SIZE, stdin);
	  printf("\n");
	  beginning = tokenized_string;
	  tokenized_string = tokenize(userInput);
	  print_tokens(tokenized_string);
	  printf("\n");
	  tokenized_string = beginning;
	  //free_tokens(tokenized_string);
    }
  printf("Goodbye.\n");
}
