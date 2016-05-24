/*
** new_alias.c for new_alias in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue May 24 09:49:37 2016 Thomas CHABOT
** Last update Tue May 24 10:57:18 2016 Thomas CHABOT
*/

#include "42sh.h"

int		new_alias(t_data *data)
{
  if (data->parser.tab_args[1] == NULL || data->parser.tab_args[2] == NULL
      || data->parser.tab_args[3] != NULL)
    return (ERROR); /* faire error alias */
  if (my_strcmp(data->parser.tab_args[1], data->parser.tab_args[2]) == SUCCESS)
    return (ERROR);
  data->alias = add_elem_alias(data->alias, data->parser.tab_args[2], \
			       data->parser.tab_args[1]);
  return (SUCCESS);
}
