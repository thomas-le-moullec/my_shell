/*
** fct_down.c for down in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh/sources/options/fct_clavier
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 17:21:34 2016 Hervé TCHIKLADZE
** Last update Sat Jun  4 20:23:10 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static void		delete_char(t_data *data, int i)
{
  char			*new;
  int			j;
  int			w;

  new = NULL;
  new = my_mallok(new, sizeof(*new) * my_strlen(data->shell.line));
  j = 0;
  w = 0;
  while (data->shell.line[w] != '\0')
    {
      if (w != i)
	new[j++] = data->shell.line[w];
      w++;
    }
  new[j] = '\0';
  data->shell.line = my_free(data->shell.line);
  data->shell.line = my_strcpy(new);
  data->shell.tmp_hist = my_free(data->shell.tmp_hist);
  data->shell.tmp_hist = my_strcpy(data->shell.line);
  new = my_free(new);
}

int             fct_supp(t_data *data, int *i)
{
  char		*tmp;

  tmp = NULL;
  if ((tmp = tgetstr("dc", NULL)) == NULL)
    exit(1);
  my_putstr(tmp, 1);
  delete_char(data, *i);
  return (SUCCESS);
}

int             fct_delete(t_data *data, int *i)
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
      tmp = NULL;
      if ((tmp = tgetstr("dc", NULL)) == NULL)
	exit(1);
      my_putstr(tmp, 1);
      delete_char(data, *i);
    }
  return (SUCCESS);
}

int		fct_reset(t_data *data, int *i)
{
  int		tmp;

  if (data->shell.line == NULL || data->shell.line[0] == '\0')
    return (STOP);
  tmp = my_strlen(data->shell.line);
  data->shell.line[0] = '\0';
  clear_print_line(data->shell.line, i, tmp);
  return (SUCCESS);
}
