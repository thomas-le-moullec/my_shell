/*
** count_occurrence.c for count_occurrence in /home/le-mou_t/rendu/PSU_2015_42sh/src/mylib
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Tue May 31 14:40:11 2016 Thomas LE MOULLEC
** Last update Tue May 31 14:41:21 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

int		count_occurrence(char *str, char c)
{
  int		nb;
  int		i;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	nb++;
      i++;
    }
  return (nb);
}
