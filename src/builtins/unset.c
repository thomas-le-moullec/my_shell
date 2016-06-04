/*
** unset.c for unset in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Wed Jun  1 21:20:02 2016 leo LE DIOURON
** Last update Sat Jun  4 11:05:06 2016 steeve payraudeau
*/

#include "42sh.h"

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

int             delete_local(t_data *data)
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

void		unset_name(t_data *data, char *str)
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
    return (my_put_error("unset: Too few arguments.\n", 1));
  while (data->parser.tab_args[j] != NULL && data->local != NULL)
    unset_name(data, data->parser.tab_args[j++]);
  return (SUCCESS);
}
