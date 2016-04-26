/*
** my_put_nbr.c for my_put_nbr in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 10:31:37 2016 Thomas CHABOT
** Last update Tue Apr 26 10:32:35 2016 Thomas CHABOT
*/

#include "42sh.h"

void            my_put_nbr(int nb, int output)
{
  int           x;

  x = 1;
  if (nb < 0)
    my_putchar('-', 2);
  else
    nb = -nb;
  while (nb / x < -9)
    x = x * 10;
  while (x)
    {
      my_putchar((-(nb / x) + '0'), output);
      nb = nb % x;
      x = x / 10;
    }
}
