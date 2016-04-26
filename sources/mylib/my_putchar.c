/*
** my_putchar.c for my_putchar in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 09:30:29 2016 Thomas CHABOT
** Last update Tue Apr 26 09:31:06 2016 Thomas CHABOT
*/

#include "42sh.h"

void    my_putchar(char c)
{
  write(1, &c, 1);
}
