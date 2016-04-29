/*
** my_epur_str.c for my_epur_str in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 10:40:46 2016 Thomas CHABOT
** Last update Wed Apr 27 17:43:45 2016 Thomas CHABOT
*/

#include "42sh.h"

char            *my_epur_str(char *str)
{
  int           i;
  int           a;
  char          *new_str;

  i = 0;
  a = 0;
  new_str = NULL;
  new_str = my_mallok(new_str, my_strlen(str) + 1);
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
        i++;
      if (a != 0 && str[i] != '\0')
        new_str[a++] = ' ';
      while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\t'))
        new_str[a++] = str[i++];
    }
  new_str[a] = '\0';
  my_free(str);
  return (new_str);
}
