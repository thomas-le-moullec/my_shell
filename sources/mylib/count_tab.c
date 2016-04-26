/*
** count_tab.c for count_tab in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 09:33:47 2016 Thomas CHABOT
** Last update Tue Apr 26 09:34:00 2016 Thomas CHABOT
*/

#include "42sh.h"

int             count_tab(char **tab)
{
  int           i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}
