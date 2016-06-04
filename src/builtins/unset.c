/*
** unset.c for unset in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Wed Jun  1 21:20:02 2016 leo LE DIOURON
** Last update Sat Jun  4 19:43:26 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static int		end_begin_local(t_data *data)
{
  if (data->local->next == NULL)
    {
      data->local->prev->next = NULL;
      data->local = data->local->prev;
      return (SUCCESS);
    }
  if (data->local->prev == NULL)
    {
      data->local->next->prev = NULL;
      data->local = data->local->next;
      return (SUCCESS);
    }
  return (SUCCESS);
}

static int		delete_local(t_data *data)
{
  if (data->local->next != NULL && data->local->prev != NULL)
    {
      data->local->next->prev = data->local->prev;
      data->local->prev->next = data->local->next;
      data->local = data->local->prev;
      return (SUCCESS);
    }
  if (data->local->prev == NULL && data->local->next == NULL)
    {
      data->local = NULL;
      return (SUCCESS);
    }
  return (end_begin_local(data));
}

void            delete_existant_local(t_data *data, char *name)
{
  if (data->local != NULL)
    {
      while (data->local->prev != NULL)
	data->local = data->local->prev;
      while (data->local->next != NULL &&
	     my_strcmp(data->local->name, name) == ERROR)
        data->local = data->local->next;
      if (my_strcmp(data->local->name, name) == SUCCESS)
	delete_local(data);
      if (data->local != NULL)
	while (data->local->next != NULL)
          data->local = data->local->next;
    }
}

static void		unset_name(t_data *data, char *str)
{
  while (data->local != NULL && data->local->prev != NULL)
    {
      if (my_strcmp(data->local->name, str) == SUCCESS)
	delete_local(data);
      if (data->local != NULL && data->local->prev != NULL)
      data->local = data->local->prev;
    }
  if (data->local != NULL && my_strcmp(data->local->name, str) == SUCCESS)
    delete_local(data);
  if (data->local != NULL && data->local->prev != NULL)
    while (data->local->next != NULL)
      data->local = data->local->next;
}

int		my_unset(t_data *data)
{
  int		j;
  int		nb;

  j = 1;
  nb = count_tab(data->parser.tab_args);
  if (nb == 1)
    return (my_put_error(ERR_SET, 1));
  while (data->parser.tab_args[j] != NULL && data->local != NULL)
    unset_name(data, data->parser.tab_args[j++]);
  return (SUCCESS);
}
