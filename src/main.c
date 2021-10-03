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
  while(*userInput != 'q')
    {
	  printf("Please enter the item to tokenize:(Enter q to exit)\n");
	  printf("$ ");
	  fgets(userInput, MAX_SIZE, stdin);
	  printf("\n");
	  beginning = tokenized_string;  //Save the beginning of the string.
	  tokenized_string = tokenize(userInput);  //Tokenize the string.
	  print_tokens(tokenized_string);  //Print the tokens.
	  printf("\n");
	  tokenized_string = beginning;  //Get back to the beginning of the string.
	  //free_tokens(tokenized_string);  //Free the tokens.(Not working)
    }
  printf("Goodbye.\n");
}
