/*
** my_show_tab.c for my_show_tab in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 09:34:12 2016 Thomas CHABOT
** Last update Fri Apr 29 10:58:11 2016 leo LE DIOURON
*/

#include "42sh.h"

void            my_show_tab(char **tab)
{
  int           i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i], 1);
      my_putchar('\n', 1);
      i++;
    }
}
