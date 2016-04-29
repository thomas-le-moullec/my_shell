/*
** my_getnbr.c for my_getnbr in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 10:33:06 2016 Thomas CHABOT
** Last update Wed Apr 27 16:13:04 2016 Thomas CHABOT
*/

#include "42sh.h"

int     my_getnbr(char *str)
{
  int   i;
  int   nb;

  nb = 0;
  i = 0;
  if (str[0] == '-')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
        return (ERROR);
      while (str[i] >= '0' && str[i] <= '9')
        {
          nb = (nb + str[i] - '0') * 10;
          i++;
        }
    }
  if (str[0] == '-')
    return ((nb / 10) * -1);
  return (nb / 10);
}
