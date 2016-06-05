/*
** new_alias.c for new_alias in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue May 24 09:49:37 2016 Thomas CHABOT
** Last update Sun Jun  5 14:13:56 2016 leo LE DIOURON
*/

#include "42sh.h"

static void		delete_existant_alias(t_data *data)
{
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
}

static int	add_end_alias(t_data *data, char *tmp)
{
  delete_existant_alias(data);
  if (my_strcmp(tmp, "alias") == SUCCESS ||
      my_strcmp(tmp, "unalias") == SUCCESS)
    return (my_put_error(DANGER, 1));
  data->alias = add_elem_alias(data->alias, tmp, \
                               data->parser.tab_args[1]);
  return (SUCCESS);

}

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
	  tmp = my_strcat(tmp, data->parser.tab_args[j++], ' ');
    }
  else
    tmp = my_strcpy("\0");
  add_end_alias(data, tmp);
  tmp = my_free(tmp);
  return (SUCCESS);
}
