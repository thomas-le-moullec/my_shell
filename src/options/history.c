/*
** history.c for history in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
**
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
**
** Started on  Tue May 17 16:05:48 2016 Hervé TCHIKLADZE
** Last update Wed Jun  1 20:04:25 2016 leo LE DIOURON
*/

#include "42sh.h"

char            *change_line_hist(t_data *data, char *tmp_hist, int y)
{
  int		i;
  int		f;
  int           k;
  char          *result;

  k = 0;
  i = 0;
  f = 0;
  result = NULL;
  result = my_mallok(result, sizeof(char) *
                     (my_strlen(data->parser.tab_pipe[y])
                      + my_strlen(data->hist->str) + 1));
  while (data->parser.tab_pipe[y][i] != '\0' && data->parser.tab_pipe[y][i] != '!')
    result[k++] = data->parser.tab_pipe[y][i++];
  while (data->hist->str[f] != '\0')
    result[k++] = data->hist->str[f++];
  f = 0;
  i++;
  while (data->parser.tab_pipe[y][i] != '\0' && tmp_hist[f++] != '\0')
    i++;
  while (data->parser.tab_pipe[y][i] != '\0')
    result[k++] = data->parser.tab_pipe[y][i++];
  result[k] = '\0';
  my_free(data->parser.tab_pipe[y]);
  return (result);
}

int		get_nb_cmd(t_data *data, char *tmp_hist, int y)
{
  int		nb;

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
  data->parser.tab_pipe[y] = change_line_hist(data, tmp_hist, y);
  while (data->hist->next != NULL)
    data->hist = data->hist->next;
  return (SUCCESS);
}

int		get_relative_cmd(t_data *data, char *tmp_hist, int y)
{
  int		nb;

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
  data->parser.tab_pipe[y] = change_line_hist(data, tmp_hist, y);
  while (data->hist->next != NULL)
    data->hist = data->hist->next;
  return (SUCCESS);
}

int		check_n_hist(t_data *data, char *tmp_hist, int y)
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

char		*take_tmp_hist(t_data *data, int y)
{
  char		*result;
  int		i;
  int		j;

  i = 0;
  j = 0;
  result = NULL;
  result = my_mallok(result, sizeof(char) * (my_strlen(data->parser.tab_pipe[y]) + 1));
  while (data->parser.tab_pipe[y][i] != '\0' && data->parser.tab_pipe[y][i] != '!')
    i++;
  if (data->parser.tab_pipe[y][i] == '\0')
    return (NULL);
  i++;
  while (data->parser.tab_pipe[y][i] != ' ' && data->parser.tab_pipe[y][i] != '\t' && data->parser.tab_pipe[y][i] != '\0')
    result[j++] = data->parser.tab_pipe[y][i++];
  result[j] = '\0';
  if (j == 0)
    return (NULL);
  return (result);
}

int		modif_args_hist(t_data *data, int y)
{
  char		*tmp_hist;

  if ((tmp_hist = take_tmp_hist(data, y)) == NULL)
    return (STOP);
  if (check_n_hist(data, tmp_hist, y) == SUCCESS)
    return (SUCCESS);
  else
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
    }
  while (data->hist->next != NULL)
    data->hist = data->hist->next;
  modif_args_hist(data, y);
  return (SUCCESS);
}

t_hist		*add_elem_key(t_hist *list, char *str)
{
  t_hist	*new_elem;

  new_elem = NULL;
  new_elem = my_mallok(new_elem, sizeof(*new_elem));
  new_elem->str = my_strcpy(str);
  new_elem = get_time(new_elem);
  if (list == NULL)
    {
      new_elem->prev = NULL;
      new_elem->next = NULL;
      new_elem->pos = 1;
      return (new_elem);
    }
  new_elem->pos = list->pos + 1;
  new_elem->prev = list;
  new_elem->next = NULL;
  list->next = new_elem;
  return (new_elem);
}
