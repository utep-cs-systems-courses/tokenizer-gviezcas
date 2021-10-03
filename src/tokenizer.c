#include <stdio.h>
#include <stdlib.h>
/*If char is a space return true.*/
int space_char(char c)
{
  if(c == ' ' || c == '\t' || c == '\n')
    {
      return 1;
    }
  return 0;
}
/*If char is not a space return true.*/
int non_space_char(char c)
{
  if(!space_char(c))
    {
      return 1;
    }
  return 0;
}
/*Iterate through string until the first char.*/
char *word_start(char *c)
{
  while(*c != '\0')
    {
      if(space_char(*c))
	{
	  c++;
	}
      else
	{
	  return c;
	}
    }
  return c;
}
/*Iterate through string until the first space.*/
char *word_end(char *c)
{
  while(*c != '\0')
    {
      if(non_space_char(*c))
	{
	  c++;
	}
      else
	{
	  return c;
	}
    }
  return c;
}
/*Iterate through string and count words.*/
int count_words(char *c)
{
  int counter = 0;
  
  while(*c != '\0')
    {
      if(space_char(*c))
	{
	  counter++;
	  c++;
	}
      else if(non_space_char(*c))
	{
	  c++;
	}
    }
  return counter;
}
/*Make a copy of the string.*/
char *copy_str(char *inStr, short len)
{
  char *copy = malloc(len * sizeof(char)+1);
  short i = 0;
  
  for(; i < len; i++)
    {
      copy[i] = inStr[i];
    }
  copy[i] = '\0';
  return copy;
}
/*Count the number of letters in a word.*/
int count_letters(char* str)
{
  int counter = 0;
  str = word_start(str);

  while(non_space_char(*str))  //Iterate through all non space characters
    {
      counter++;               //Add to the counter.
      str++;                   //Move the pointer over.
    }
  return counter;
}
/*Print the tokens in this format [1]Token.*/
void print_tokens(char **tokens)
{
  int i = 1;
  char **temp = tokens;        //Temp pointer to modify.
  
  while(*temp != 0)
    {
      printf("[%d]", i);
      printf("%s\n", *temp);
      temp++;
      i++;
    }
}
/*Free the allocated memory being used.*/
void free_tokens(char **tokens)
{
  char **temp = tokens;     //Temp pointer to modify.
  int i = 0;
  while(*temp != 0)
    {
      free(temp[i]);
      i++;
    }
  free(temp);
}

char **tokenize(char* str)
{
  char **tokenized_string = malloc((count_words(str)+1) * sizeof(char));
  char **beginning = malloc((count_words(str)+1) * sizeof(char));
  beginning = tokenized_string;  //Save the beginning of the string.
  while(*str != '\0') //Iterate through string.
    {
      str = word_start(str);  //Get to the start of the first word in string.
      *tokenized_string = copy_str(str, count_letters(str));  //Copy the string.
      str = word_end(str);  //Get to the end of the first word in sting.
      tokenized_string++;  //Move the array of string pointer over 4 bytes.
      str = word_start(str);  //Get to start of the next word.
    }
  *tokenized_string = 0;  //Add terminator to end of array of strings.
  tokenized_string = beginning;  //Get to the start of the array of strings.
  return tokenized_string;  //Return the pointer to the array of strings.
}
