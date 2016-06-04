/*
** special_history.c for special_history in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Thu Jun  2 14:05:56 2016 leo LE DIOURON
** Last update Sat Jun  4 20:04:51 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static int		get_nb_cmd(t_data *data, char *tmp_hist, int y)
{
  int			nb;

  nb = 0;
  if ((nb = my_getnbr(tmp_hist)) == ERROR)
    return (ERROR);
  while (data->hist->prev != NULL)
    data->hist = data->hist->prev;
  while (data->hist->next != NULL && nb > 0)
    {
      data->hist = data->hist->next;
      nb--;
    }
  if (nb != 0)
    return (ERROR);
  data->parser.tab_pipe[y] = change_line_hist(data, tmp_hist, y);
  while (data->hist->next != NULL)
    data->hist = data->hist->next;
  return (SUCCESS);
}

static int		get_relative_cmd(t_data *data, char *tmp_hist, int y)
{
  int			nb;

  nb = 0;
  tmp_hist = &tmp_hist[1];
  if ((nb = my_getnbr(tmp_hist)) == ERROR || nb == 0)
    return (ERROR);
  tmp_hist = my_strcat("\0", tmp_hist, '-');
  while (data->hist->prev != NULL && nb > 0)
    {
      data->hist = data->hist->prev;
      nb--;
    }
  if (nb != 0)
    return (ERROR);
  data->parser.tab_pipe[y] = change_line_hist(data, tmp_hist, y);
  while (data->hist->next != NULL)
    data->hist = data->hist->next;
  return (SUCCESS);
}

int             check_n_hist(t_data *data, char *tmp_hist, int y)
{
  if (tmp_hist[0] == '!')
    {
      if (data->hist->prev != NULL)
        {
          data->hist = data->hist->prev;
          data->parser.tab_pipe[y] = change_line_hist(data, tmp_hist, y);
          modif_args_hist(data, y);
          return (SUCCESS);
        }
      return (SUCCESS);
    }
  if (tmp_hist[0] != '-' \
      && (tmp_hist[0] < '0' \
          || tmp_hist[0] > '9'))
    return (STOP);
  if (tmp_hist[0] == '-')
    if (get_relative_cmd(data, tmp_hist, y) == ERROR)
      return (ERROR);
  if (tmp_hist[0] != '-')
    if (get_nb_cmd(data, tmp_hist, y) == ERROR)
      return (ERROR);
  modif_args_hist(data, y);
  return (SUCCESS);
}
