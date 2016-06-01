/*
** new_alias.c for new_alias in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue May 24 09:49:37 2016 Thomas CHABOT
** Last update Wed Jun  1 15:48:55 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

int		new_alias(t_data *data)
{
  char		*tmp;
  int		j;

  j = 3;
  tmp = NULL;
  if (data->parser.tab_args[1] == NULL)
    {
      if (data->alias != NULL)
	show_alias(data);
      return (SUCCESS);
    }
  if (data->parser.tab_args[2] != NULL)
    {
      tmp = my_strcpy(data->parser.tab_args[2]);
      while (data->parser.tab_args[j] != NULL)
	{
	  tmp = my_strcat(tmp, data->parser.tab_args[j], ' ');
	  j++;
	}
    }
  else
    tmp = my_strcpy("\0");
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
  data->alias = add_elem_alias(data->alias, tmp, \
			       data->parser.tab_args[1]);
  return (SUCCESS);
}
