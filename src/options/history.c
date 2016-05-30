/*
** history.c for history in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 16:05:48 2016 Hervé TCHIKLADZE
** Last update Mon May 30 18:33:34 2016 Thomas CHABOT
*/

#include "42sh.h"

int		modif_args_hist(t_data *data, int i) /* BOUCLE SUR !! */
{
  if (data->parser.tab_args[i][0] != '!')  /* ERROR A REVOIR*/
    return (STOP);
  data->parser.tab_args[i] = &data->parser.tab_args[i][1];
  if (data->parser.tab_args[i][0] == '!')
    {
      data->parser.tab_args[i] = NULL;
      data->parser.tab_args[i] = my_strcpy(data->hist->prev->str);
    }
  else
    {
      while (data->hist->prev != NULL &&
	     my_strncmp(data->hist->str, data->parser.tab_args[i],
			my_strlen(data->parser.tab_args[i])) == ERROR)
	data->hist = data->hist->prev;
      if (data->hist->prev != NULL ||
	  my_strncmp(data->hist->str, data->parser.tab_args[i],
	   my_strlen(data->parser.tab_args[i])) == SUCCESS)
	{
	  data->parser.tab_args[i] = NULL;
	  data->parser.tab_args[i] = my_strcpy(data->hist->str);
	}
      else
	return (error_event(data, data->parser.tab_args[i]));
    }
  while (data->hist->next != NULL)
    data->hist = data->hist->next;
  return (SUCCESS);
}

t_hist		*add_elem_key(t_hist *list, char *str)
{
  t_hist	*new_elem;

  new_elem = NULL;
  new_elem = my_mallok(new_elem, sizeof(*new_elem));
  new_elem->str = my_strcpy(str);
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

int		print_list(t_data *data)
{
  int		nb_line;

  nb_line = 0;
  if (data->hist == NULL)
    return (ERROR);
  while (data->hist->prev != NULL)
    data->hist = data->hist->prev;
  while (data->hist->next != NULL)
    {
      my_put_nbr(nb_line++, 1);
      my_putchar(' ', 1);
      my_putstr(data->hist->str, 1);
      my_putstr("\n", 1);
      data->hist = data->hist->next;
    }
  my_put_nbr(nb_line++, 1);
  my_putchar(' ', 1);
  my_putstr(data->hist->str, 1);
  my_putstr("\n", 1);
  return (SUCCESS);
}
