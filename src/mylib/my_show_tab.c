/*
** my_show_tab.c for my_show_tab in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 09:34:12 2016 Thomas CHABOT
** Last update Tue May 17 17:45:56 2016 Hervé TCHIKLADZE
*/

#include "42sh.h"

void            my_show_env(char **tabo, int fd)
{
  int           i;

  i = 0;
  while (tabo[i] != NULL)
    {
      my_putstr(tabo[i], fd);
      my_putchar('\n', fd);
      i++;
    }
}

void            my_show_tab(char **tabo)
{
  int           i;

  i = 0;
  while (tabo[i] != NULL)
    {
      my_putstr(tabo[i], 1);
      my_putchar('\n', 1);
      i++;
    }
}
