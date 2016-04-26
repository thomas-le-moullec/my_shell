/*
** my_strcmp.c for my_strcmp in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 10:24:58 2016 Thomas CHABOT
** Last update Tue Apr 26 10:27:19 2016 Thomas CHABOT
*/

#include "42sh.h"

int		my_strcmp(char *src, char *dest)
{
  int		i;

  i = 0;
  if (my_strlen(src) != my_strlen(dest))
    return (ERROR);
  while (src[i] != '\0' && dest[i] != '\0')
    {
      if (src[i] != dest[i])
	return (ERROR);
      i++;
    }
  return (SUCCESS);
}
