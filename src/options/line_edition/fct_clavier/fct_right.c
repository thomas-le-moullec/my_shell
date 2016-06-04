/*
** fct_right.c for right in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh/sources/options/fct_clavier
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 17:21:48 2016 Hervé TCHIKLADZE
** Last update Sat Jun  4 20:31:30 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

int		fct_right(t_data *data, int *i)
{
  char		*tmp;

  tmp = NULL;
  if (data->shell.line == NULL)
    return (STOP);
  if ((*i) < my_strlen(data->shell.line))
    {
      (*i) += 1;
      if ((tmp = tgetstr("nd", NULL)) == NULL)
	exit(1);
      my_putstr(tmp, 1);
    }
  return (SUCCESS);
}
