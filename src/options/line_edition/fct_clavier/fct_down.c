/*
** fct_down.c for down in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh/sources/options/fct_clavier
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 17:21:34 2016 Hervé TCHIKLADZE
** Last update Sat Jun  4 20:27:44 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

void		clear_print_line(char *line, int *i, int tmp)
{
  char		*str_tmp;

  str_tmp = NULL;
  while ((*i) < tmp)
    {
      if ((str_tmp = tgetstr("nd", NULL)) == NULL)
	exit(1);
      my_putstr(str_tmp, 1);
      (*i)++;
    }
  while (tmp > 0)
    {
      str_tmp = NULL;
      if ((str_tmp = tgetstr("le", NULL)) == NULL)
	exit(1);
      my_putstr(str_tmp, 1);
      str_tmp = NULL;
      if ((str_tmp = tgetstr("dc", NULL)) == NULL)
	exit(1);
      my_putstr(str_tmp, 1);
      tmp--;
    }
  (*i) = my_strlen(line);
  my_putstr(line, 1);
}

int             fct_down(t_data *data, int *i)
{
  int		tmp;

  tmp = my_strlen(data->shell.line);
  if (data->hist == NULL)
    return (STOP);
  if (data->hist->next == NULL)
    {
      data->shell.line = my_free(data->shell.line);
      data->shell.line = my_strcpy(data->shell.tmp_hist);
      data->shell.pos_list = 0;
    }
  if (data->hist->next != NULL)
    {
      data->shell.line = my_free(data->shell.line);
      data->hist = data->hist->next;
      data->shell.line = my_strcpy(data->hist->str);
    }
  clear_print_line(data->shell.line, i, tmp);
  return (SUCCESS);
}
