/*
** alias.c for alias in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Wed May 18 16:23:34 2016 Thomas CHABOT
** Last update Sun Jun  5 13:46:23 2016 leo LE DIOURON
*/

#include "42sh.h"

static void              find_valid_alias_loop(t_data *data, int *a, char *tmp)
{
  while (data->alias->prev != NULL && *a == 0)
    if (my_strcmp(tmp, data->alias->name) == SUCCESS)
      *a = 1;
    else
      data->alias = data->alias->prev;
}

int              find_valid_alias(t_data *data, int i, int *j)
{
  int                   x;
  int                   a;
  int                   f;
  char                  *tmp;

  a = 0;
  f = -1;
  x = check_alias_in(data, i, j);
  tmp = NULL;
  tmp = my_mallok(tmp, sizeof(*tmp) *
                  (my_strlen(data->parser.tab_pipe[i]) + 1));
  while (++f < *j);
  while (f < x)
    tmp[a++] = data->parser.tab_pipe[i][f++];
  tmp[a] = '\0';
  a = 0;
  find_valid_alias_loop(data, &a, tmp);
  if (my_strcmp(tmp, data->alias->name) == SUCCESS)
    a = 1;
  if (my_strcmp(tmp, data->alias->name) == SUCCESS && data->alias->flag == 1)
    data->shell.alias_loop = 1;
  if (data->alias->cmd == NULL || data->alias->cmd[0] == '\0')
    a = 0;
  free(tmp);
  return (a);
}


t_alias		*add_elem_alias(t_alias *alias, char *cmd, char *name)
{
  t_alias	*new_elem;

  new_elem = NULL;
  new_elem = my_mallok(new_elem, sizeof(*new_elem));
  new_elem->cmd = my_strcpy(cmd);
  new_elem->name = my_strcpy(name);
  if (alias == NULL)
    {
      new_elem->prev = NULL;
      new_elem->next = NULL;
      new_elem->flag = 0;
      return (new_elem);
    }
  new_elem->prev = alias;
  new_elem->next = NULL;
  new_elem->flag = 0;
  alias->next = new_elem;
  return (new_elem);
}
