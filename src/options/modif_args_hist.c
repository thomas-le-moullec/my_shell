/*
** modif_args_hist.c for modif in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Sat Jun  4 11:28:45 2016 Hervé TCHIKLADZE
** Last update Sat Jun  4 11:31:23 2016 Hervé TCHIKLADZE
*/

#include "42sh.h"

int             modif_args_hist_check(t_data *data, int y, char *tmp_hist)
{
  while (data->hist->prev != NULL \
	 && my_strncmp(data->hist->str, tmp_hist,
		       my_strlen(tmp_hist)) == ERROR)
    data->hist = data->hist->prev;
  if (data->hist->prev != NULL ||
      my_strncmp(data->hist->str, tmp_hist,
		 my_strlen(tmp_hist)) == SUCCESS)
    data->parser.tab_pipe[y] = change_line_hist(data, tmp_hist, y);
  else
    return (error_event(data, tmp_hist));
  return (SUCCESS);
}

int             modif_args_hist(t_data *data, int y)
{
  char          *tmp_hist;

  if ((tmp_hist = take_tmp_hist(data, y, 0, 0)) == NULL)
    return (STOP);
  if (check_n_hist(data, tmp_hist, y) == SUCCESS)
    {
      tmp_hist = my_free(tmp_hist);
      return (SUCCESS);
    }
  else
    if (modif_args_hist_check(data, y, tmp_hist) == ERROR)
      return (ERROR);
  while (data->hist->next != NULL)
    data->hist = data->hist->next;
  tmp_hist = my_free(tmp_hist);
  modif_args_hist(data, y);
  tmp_hist = my_free(tmp_hist);
  return (SUCCESS);
}
