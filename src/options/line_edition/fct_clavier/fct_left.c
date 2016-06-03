/*
** fct_left.c for left in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh/sources/options/fct_clavier
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 17:23:21 2016 Hervé TCHIKLADZE
** Last update Thu Jun  2 10:11:42 2016 steeve payraudeau
*/

#include "42sh.h"

int		fct_left(t_data *data, int *i)
{
  if (data->shell.line == NULL)
    return (STOP);
  if ((*i) > 0)
    {
      (*i) -= 1;
      my_putstr(tgetstr("le", NULL), 1);
    }
  return (SUCCESS);
}
