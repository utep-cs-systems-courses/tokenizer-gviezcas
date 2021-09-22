#include <stdio.h>
#include <stdlib.h>

int space_char(char c)
{
  if(c == ' ' || c == '\t' || c == '\n')
    {
      return 1;
    }
  return 0;
}

int non_space_char(char c)
{
  if(!space_char(c))
    {
      return 1;
    }
  return 0;
}

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

char *copy_str(char *inStr, short len)
{
  char *copy = malloc(len * sizeof(char));
  short i = 0;
  
  for(; i < len; i++)
    {
      copy[i] = inStr[i];
    }
  copy[i] = '\0';
  return copy;
}

int count_letters(char* str)
{
  int counter = 0;
  str = word_start(str);

  while(non_space_char(*str))
    {
      counter++;
      str++;
    }
  return counter;
}

char **tokenize(char* str)
{
  char **tokenized_string = malloc(count_words(str)* sizeof(char));
  int i = 1;
  while(*str != '\0')
    {
      str = word_start(str);
      *tokenized_string = copy_str(str, count_letters(str));
      str = word_end(str);
      printf("[%d]", i);
      puts(*tokenized_string);
      tokenized_string++;
      str = word_start(str);
      i++;
    }
  
  return tokenized_string;
}
