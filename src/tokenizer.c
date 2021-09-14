#include <stdio.h>

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
