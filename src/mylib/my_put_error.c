/*
** my_put_error.c for my_put_error in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue May 24 13:20:04 2016 Thomas CHABOT
** Last update Tue May 24 13:26:32 2016 Thomas CHABOT
*/

#include "42sh.h"

int		my_put_error(char *str, int out)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i], out);
      i++;
    }
  return (ERROR);
}
