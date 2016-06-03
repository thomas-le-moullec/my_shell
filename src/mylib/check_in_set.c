/*
** check_in_set.c for check_in_set in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Jun  3 13:20:30 2016 leo LE DIOURON
** Last update Fri Jun  3 16:34:58 2016 leo LE DIOURON
*/

#include "42sh.h"

char	*check_in_alias(t_data *data, char *str)
{
  char	*result;

  result = NULL;
  if (data->alias != NULL)
    {
      while (data->alias->prev != NULL)
	data->alias = data->alias->prev;
      while (data->alias->next != NULL &&
	     my_strcmp(data->alias->name, str) == ERROR)
	data->alias = data->alias->next;
      if (my_strcmp(data->alias->name, str) != ERROR)
	result = my_strcpy(data->alias->cmd);
    }
  return (result);
}

char	*check_in_set(t_data *data, char *str)
{
  char	*result;

  result = NULL;
  if (data->local != NULL)
    {
      while (data->local->prev != NULL)
	data->local = data->local->prev;
      while (data->local->next != NULL &&
	     my_strcmp(data->local->name, str) == ERROR)
	data->local = data->local->next;
      if (my_strcmp(data->local->name, str) != ERROR)
	result = my_strcpy(data->local->cmd);
    }
  return (result);
}
