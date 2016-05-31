/*
** history.c for history in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
**
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
**
** Started on  Tue May 17 16:05:48 2016 Hervé TCHIKLADZE
** Last update Tue May 31 14:54:28 2016 Thomas CHABOT
*/

#include "42sh.h"

int		get_nb_cmd(t_data *data, int i)
{
  int		nb;

  nb = 0;
  if ((nb = my_getnbr(data->parser.tab_args[i])) == ERROR)
    return (ERROR);
  while (data->hist->prev != NULL)
    data->hist = data->hist->prev;
  while (data->hist->next != NULL && nb > 0)
    {
      data->hist = data->hist->next;
      nb--;
    }
  data->parser.tab_args[i] = my_strcpy(data->hist->str);
  while (data->hist->next != NULL)
    data->hist = data->hist->next;
  return (SUCCESS);
}

int		get_relative_cmd(t_data *data, int i)
{
  int		nb;

  nb = 0;
  data->parser.tab_args[i] = &data->parser.tab_args[i][1];
  if ((nb = my_getnbr(data->parser.tab_args[i])) == ERROR)
    return (ERROR);
  while (data->hist->prev != NULL && nb > 0)
    {
      data->hist = data->hist->prev;
      nb--;
    }
  data->parser.tab_args[i] = my_strcpy(data->hist->str);
  while (data->hist->next != NULL)
    data->hist = data->hist->next;
  return (SUCCESS);
}

int		check_n_hist(t_data *data, int i)
{
  if (data->parser.tab_args[i][0] != '-' \
      && (data->parser.tab_args[i][0] < '0' \
	  || data->parser.tab_args[i][0] > '9'))
    return (STOP);
  if (data->parser.tab_args[i][0] == '-')
    if (get_relative_cmd(data, i) == ERROR)
      return (ERROR);
  if (data->parser.tab_args[i][0] != '-')
    if (get_nb_cmd(data, i) == ERROR)
      return (ERROR);
  modif_args_hist(data, i);
  return (SUCCESS);
}

int		modif_args_hist(t_data *data, int i)
{
  if (data->parser.tab_args[i][0] != '!')
    return (STOP);
  data->parser.tab_args[i] = &data->parser.tab_args[i][1];
  if (check_n_hist(data, i) == SUCCESS)
    return (SUCCESS);
  if (data->parser.tab_args[i][0] == '!')
    data->parser.tab_args[i] = my_strcpy(data->hist->prev->str);
  else
    {
      while (data->hist->prev != NULL \
	     && my_strncmp(data->hist->str, data->parser.tab_args[i],
			my_strlen(data->parser.tab_args[i])) == ERROR)
	data->hist = data->hist->prev;
      if (data->hist->prev != NULL ||
	  my_strncmp(data->hist->str, data->parser.tab_args[i],
	   my_strlen(data->parser.tab_args[i])) == SUCCESS)
	data->parser.tab_args[i] = my_strcpy(data->hist->str);
      else
	return (error_event(data, data->parser.tab_args[i]));
    }
  while (data->hist->next != NULL)
    data->hist = data->hist->next;
  modif_args_hist(data, i);
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
