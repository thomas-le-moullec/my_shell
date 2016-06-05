/*
** get_which.c for get_which in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Sun Jun  5 14:25:23 2016 Thomas CHABOT
** Last update Sun Jun  5 14:25:54 2016 Thomas CHABOT
*/

#include "42sh.h"

char			*get_which(char *str)
{
  char                  *new_str;
  int                   i;
  int                   j;

  new_str = NULL;
  i = my_strlen(str);
  j = 0;
  while (i > 0 && str[i] != '/')
    i--;
  if (i > 0)
    i--;
  while (i > 0 && str[i] != '/')
    i--;
  new_str = my_mallok(new_str, sizeof(*new_str) * (my_strlen(str) + 1));
  while (str[i])
    new_str[j++] = str[i++];
  new_str[j] = '\0';
  return (new_str);
}
