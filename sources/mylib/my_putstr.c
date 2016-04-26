/*
** my_putstr.c for my_putstr in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 09:31:27 2016 Thomas CHABOT
** Last update Tue Apr 26 09:31:42 2016 Thomas CHABOT
*/

#include "42sh.h"

void    my_putstr(char  *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
