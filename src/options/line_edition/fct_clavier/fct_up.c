/*
** fct_up.c for up in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh/sources/options/fct_clavier
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 17:20:07 2016 Hervé TCHIKLADZE
** Last update Fri Jun  3 21:14:27 2016 Thomas CHABOT
*/

#include "42sh.h"

int		fct_up(t_data *data, int *i)
{
  int		tmp;

  tmp = my_strlen(data->shell.line);
  if (data->hist != NULL)
    {
      data->shell.line = my_free(data->shell.line);
      if (data->hist->prev != NULL && data->shell.pos_list == 1)
	{
	  data->hist = data->hist->prev;
	  data->shell.line = my_strcpy(data->hist->str);
	}
      else
	{
	  data->shell.line = my_strcpy(data->hist->str);
	  data->shell.pos_list = 1;
	}
      clear_print_line(data->shell.line, i, tmp);
    }
  return (SUCCESS);
}
