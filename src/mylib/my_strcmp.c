/*
** my_strcmp.c for my_strcmp in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 10:24:58 2016 Thomas CHABOT
** Last update Wed Jun  1 20:02:32 2016 steeve payraudeau
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

int		my_strncmp(char *one, char *two, int n)
{
  int           i;

  i = 0;
  while (i < n && one[i] != '\0' && two[i] != '\0')
    {
      if (one[i] != two[i])
	return (ERROR);
      i++;
    }
  return (SUCCESS);
}

int		my_strcmp_equal(char *src, char *dest)
{
  int		i;

  i = 0;
  while (src[i] != '\0' && dest[i] != '\0' && dest[i] != '=')
    {
      if (src[i] != dest[i])
	return (ERROR);
      i++;
    }
  if (dest[i] == '=' && src[i] == '\0')
    return (SUCCESS);
  return (ERROR);
}
