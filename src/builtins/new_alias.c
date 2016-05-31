/*
** new_alias.c for new_alias in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue May 24 09:49:37 2016 Thomas CHABOT
** Last update Tue May 31 18:23:50 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

int		new_alias(t_data *data)
{
  if (data->parser.tab_args[1] == NULL)
    {
      if (data->alias != NULL)
	show_alias(data);
      return (SUCCESS);
    }
  if (data->parser.tab_args[1] != NULL && data->parser.tab_args[2] == NULL)
    return (SUCCESS);
  if (my_strcmp(data->parser.tab_args[1], data->parser.tab_args[2]) == SUCCESS)
    return (ERROR);
  if (data->alias != NULL)
    {
      while (data->alias->prev != NULL)
	data->alias = data->alias->prev;
      while (data->alias->next != NULL &&
	     my_strcmp(data->alias->name, data->parser.tab_args[1]) == ERROR)
	data->alias = data->alias->next;
      if (my_strcmp(data->alias->name, data->parser.tab_args[1]) == SUCCESS)
	delete_alias(data);
      if (data->alias != NULL)
	while (data->alias->next != NULL)
	  data->alias = data->alias->next;
    }
  data->alias = add_elem_alias(data->alias, data->parser.tab_args[2], \
			       data->parser.tab_args[1]);
  return (SUCCESS);
}
