/*
** fct_down.c for down in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh/sources/options/fct_clavier
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 17:21:34 2016 Hervé TCHIKLADZE
** Last update Sat Jun  4 20:30:40 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

int             fct_kome(t_data *data, int *i)
{
  char		*tmp;

  tmp = NULL;
  if (data->shell.line == NULL)
    return (STOP);
  while ((*i) > 0)
    {
      if ((tmp = tgetstr("le", NULL)) == NULL)
	exit(1);
      my_putstr(tmp, 1);
      (*i)--;
    }
  return (SUCCESS);
}

int             fct_end(t_data *data, int *i)
{
  char		*tmp;

  tmp = NULL;
  if (data->shell.line == NULL)
    return (STOP);
  while ((*i) < my_strlen(data->shell.line))
    {
      if ((tmp = tgetstr("nd", NULL)) == NULL)
	exit(1);
      my_putstr(tmp, 1);
      (*i)++;
    }
  return (SUCCESS);
}
