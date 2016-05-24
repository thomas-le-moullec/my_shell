/*
** unalias.c for unalias in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue May 24 10:15:56 2016 Thomas CHABOT
** Last update Tue May 24 10:52:15 2016 Thomas CHABOT
*/

#include "42sh.h"

void		delete_alias(t_data *data)
{
  if (data->alias->next != NULL && data->alias->prev != NULL)
    {
      data->alias->next->prev = data->alias->prev;
      data->alias->prev->next = data->alias->next;
      data->alias = data->alias->next;
    }
  if (data->alias->next == NULL)
    {
      data->alias->prev->next = NULL;
      data->alias = data->alias->prev;
    }
  if (data->alias->prev == NULL)
    {
      data->alias->next->prev = NULL;
      data->alias = data->alias->next;
    }
}

int		unalias(t_data *data)
{
  if (data->parser.tab_args[1] == NULL || data->parser.tab_args[2] != NULL)
    return (ERROR); /* faire gestion erreur */
  while (data->alias->prev != NULL)
    {
      if (my_strcmp(data->parser.tab_args[1], data->alias->name) == SUCCESS)
	delete_alias(data);
      if (data->alias->prev != NULL)
	data->alias = data->alias->prev;
    }
  printf("--> %s\n", data->alias->name);
  if (my_strcmp(data->parser.tab_args[1], data->alias->name) == SUCCESS)
    delete_alias(data);
  while (data->alias->next != NULL)
    data->alias = data->alias->next;
  return (SUCCESS);
}
