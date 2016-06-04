/*
** fct_left.c for left in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh/sources/options/fct_clavier
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 17:23:21 2016 Hervé TCHIKLADZE
** Last update Sat Jun  4 20:29:06 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

int		fct_left(t_data *data, int *i)
{
  char		*tmp;

  tmp = NULL;
  if (data->shell.line == NULL)
    return (STOP);
  if ((*i) > 0)
    {
      (*i) -= 1;
      if ((tmp = tgetstr("le", NULL)) == NULL)
	exit(1);
      my_putstr(tmp, 1);
    }
  return (SUCCESS);
}
