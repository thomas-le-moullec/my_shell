/*
** get_dir.c for get_dir in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue May 24 16:11:52 2016 Thomas CHABOT
** Last update Tue May 24 16:12:54 2016 Thomas CHABOT
*/

#include "42sh.h"

char            *get_dir(char *str)
{
  int           i;
  int           j;
  char          *new_str;

  i = 0;
  new_str = NULL;
  new_str = my_mallok(new_str, my_strlen(str) + 1);
  while (str[i] && (str[i] == '.' || str[i] == '/'))
    i++;
  j = 0;
  while (str[i])
    new_str[j++] = str[i++];
  new_str[j] = '\0';
  return (new_str);
}
