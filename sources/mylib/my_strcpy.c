/*
** my_strcpy.c for my_strcpy in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 16:50:20 2016 Thomas CHABOT
** Last update Mon May 16 17:45:17 2016 leo LE DIOURON
*/

#include "42sh.h"

char		*my_strcpy_equal(char *str)
{
  char		*new_str;
  int		i;
  int		j;

  i = 0;
  j = 0;
  new_str = NULL;
  while (str[i] != '\0' && str[i] != '=')
    i++;
  if (str[i] != '=')
    return (NULL);
  i++;
  if (str[i] == '\0')
    return (NULL);
  new_str = my_mallok(new_str, my_strlen(str) - i + 1);
  while (str[i] != '\0')
    new_str[j++] = str[i++];
  new_str[j] = '\0';
  return (new_str);
}

char		*my_strcpy_empty(char *str)
{
  char		*new_str;
  int		i;

  i = 0;
  new_str = NULL;
  new_str = my_mallok(new_str, my_strlen(str) + 2);
  while (str[i] != '\0')
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i++] = '=';
  new_str[i] = '\0';
  return (new_str);
}

char		*my_strcpy(char *str)
{
  char		*new_str;
  int		i;

  i = 0;
  new_str = NULL;
  new_str = my_mallok(new_str, my_strlen(str) + 1);
  while (str[i] != '\0')
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}

char		*my_strcpy_full(char *one, char *two)
{
  char		*new_str;
  int		i;
  int		j;

  i = 0;
  j = 0;
  new_str = NULL;
  new_str = my_mallok(new_str, my_strlen(one) + my_strlen(two) + 2);
  while (one[i] != '\0')
    new_str[j++] = one[i++];
  i = 0;
  new_str[j++] = '=';
  while (two[i] != '\0')
    new_str[j++] = two[i++];
  new_str[j] = '\0';
  return (new_str);
}

char		*my_cpy(char *one, char *two)
{
  int		i;

  i = 0;
  while (two[i] != '\0')
    {
      one[i] = two[i];
      i++;
    }
  one[i] = '\0';
  return (one);
}
