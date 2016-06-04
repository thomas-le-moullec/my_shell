/*
** change_alias.c for change_alias in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Mon May 23 17:45:40 2016 Hervé TCHIKLADZE
** Last update Sat Jun  4 19:47:47 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static void            modify_string_alias(t_data *data, int i, int j, int f)
{
  int           k;
  char          *result;

  k = 0;
  result = NULL;
  result = my_mallok(result, sizeof(*result) *
		     (my_strlen(data->parser.tab_pipe[i])
		      + my_strlen(data->alias->cmd) + 1));
  while (k < j)
    {
      result[k] = data->parser.tab_pipe[i][k];
      k++;
    }
  while (data->alias->cmd[f] != '\0')
    result[k++] = data->alias->cmd[f++];
  f = 0;
  while (data->parser.tab_pipe[i][j] != '\0' && data->alias->name[f++] != '\0')
    j++;
  while (data->parser.tab_pipe[i][j] != '\0')
    result[k++] = data->parser.tab_pipe[i][j++];
  result[k] = '\0';
  data->parser.tab_pipe[i] = my_free(data->parser.tab_pipe[i]);
  data->parser.tab_pipe[i] = my_strcpy(result);
  result = my_free(result);
}

static int             check_alias_in(t_data *data, int i, int *j)
{
  int           x;

  while (data->parser.tab_pipe[i][*j] != '\0' &&
         (data->parser.tab_pipe[i][*j] == ' ' ||
          data->parser.tab_pipe[i][*j] == '\t'))
    (*j)++;
  x = *j;
  while (data->parser.tab_pipe[i][x] != '\0' &&
         data->parser.tab_pipe[i][x] != ' ' &&
         data->parser.tab_pipe[i][x] != '\t')
    x++;
  return (x);
}

static int		find_valid_alias(t_data *data, int i, int *j)
{
  int			x;
  int			a;
  int			f;
  char			*tmp;

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
  while (data->alias->prev != NULL && a == 0)
    if (my_strcmp(tmp, data->alias->name) == SUCCESS)
      a = 1;
    else
      data->alias = data->alias->prev;
  if (my_strcmp(tmp, data->alias->name) == SUCCESS)
    a = 1;
  free(tmp);
  return (a);
}

static void		change_alias_loop(t_data *data, int i, int *j, int a)
{
  int			k;

  k = 0;
  if (a == 1)
    {
      modify_string_alias(data, i, *j, 0);
      while (data->parser.tab_pipe[i][*j] != '\0' &&
	     data->alias->cmd[k++] != '\0')
	(*j)++;
    }
  else
    while (data->parser.tab_pipe[i][*j] != '\0' &&
	   (data->parser.tab_pipe[i][*j] != ' ' &&
	    data->parser.tab_pipe[i][*j] != '\t'))
      (*j)++;
}

int            change_alias(t_data *data, int i)
{
  int           j;
  int           a;

  j = 0;
  a = 0;
  if (data->alias != NULL)
    {
      a = find_valid_alias(data, i, &j);
      change_alias_loop(data, i, &j, a);
      if (a == 1)
	return (1);
      else
	while (data->alias->next != NULL)
	  data->alias = data->alias->next;
    }
  return (SUCCESS);
}
