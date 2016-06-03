/*
** fct_down.c for down in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh/sources/options/fct_clavier
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 17:21:34 2016 Hervé TCHIKLADZE
** Last update Thu Jun  2 10:22:24 2016 steeve payraudeau
*/

#include "42sh.h"

int             fct_kome(t_data *data, int *i)
{
  if (data->shell.line == NULL)
    return (STOP);
  while ((*i) > 0)
    {
      my_putstr(tgetstr("le", NULL), 1);
      (*i)--;
    }
  return (SUCCESS);
}

int             fct_end(t_data *data, int *i)
{
  if (data->shell.line == NULL)
    return (STOP);
  while ((*i) < my_strlen(data->shell.line))
    {
      my_putstr(tgetstr("nd", NULL), 1);
      (*i)++;
    }
  return (SUCCESS);
}
