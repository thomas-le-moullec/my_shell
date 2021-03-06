/*
** unalias.c for unalias in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue May 24 10:15:56 2016 Thomas CHABOT
** Last update Sat Jun  4 19:18:34 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static int	end_begin_alias(t_data *data)
{
  if (data->alias->next == NULL)
    {
      data->alias->prev->next = NULL;
      data->alias = data->alias->prev;
      return (SUCCESS);
    }
  if (data->alias->prev == NULL)
    {
      data->alias->next->prev = NULL;
      data->alias = data->alias->next;
      return (SUCCESS);
    }
  return (SUCCESS);
}

int		delete_alias(t_data *data)
{
  if (data->alias->next != NULL && data->alias->prev != NULL)
    {
      data->alias->next->prev = data->alias->prev;
      data->alias->prev->next = data->alias->next;
      data->alias = data->alias->prev;
      return (SUCCESS);
    }
  if (data->alias->prev == NULL && data->alias->next == NULL)
    {
      data->alias = NULL;
      return (SUCCESS);
    }
  return (end_begin_alias(data));
}

int		unalias(t_data *data)
{
  int		j;

  j = 1;
  if (data->parser.tab_args[1] == NULL)
    return (my_put_error(ERROR_UNALIAS, 1));
  while (data->parser.tab_args[j] != NULL)
    {
      while (data->alias->prev != NULL)
	{
	  if (my_strcmp(data->parser.tab_args[j], data->alias->name) == SUCCESS)
	    delete_alias(data);
	  if (data->alias->prev != NULL)
	    data->alias = data->alias->prev;
	}
      if (my_strcmp(data->parser.tab_args[j], data->alias->name) == SUCCESS)
	delete_alias(data);
      if (data->alias != NULL)
	while (data->alias->next != NULL)
	  data->alias = data->alias->next;
      j++;
    }
  return (SUCCESS);
}
