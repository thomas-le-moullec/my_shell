/*
** my_setenv.c for my_setenv in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 16:40:35 2016 Thomas CHABOT
** Last update Wed Apr 27 20:15:18 2016 Thomas CHABOT
*/

#include "42sh.h"

int		check_env_exist(t_data *data, char *str)
{
  int		i;

  i = 0;
  if (data->shell.env == NULL)
    return (ERROR);
  while (data->shell.env[i] != NULL)
    {
      if (my_strcmp_equal(str, data->shell.env[i]) == SUCCESS)
	return (i);
      i++;
    }
  return (ERROR);
}

char		**fill_env_none(t_data *data, int i, int *j, char **new_env)
{
  if (i < 0)
    {
      new_env = my_mallok(new_env, count_tab(data->shell.env) + 2);
      while (data->shell.env[*j] != NULL)
	{
	  new_env[*j] = my_strcpy(data->shell.env[*j]);
	  (*j)++;
	}
      new_env[*j] = my_strcpy_empty(data->parser.tab_args[1]);
      (*j)++;
    }
  return (new_env);
}

char		**fill_env(t_data *data, int value)
{
  char		**new_env;
  int		i;
  int		j;

  j = 0;
  new_env = NULL;
  if ((i = check_env_exist(data, data->parser.tab_args[1])) > 0)
    {
      new_env = my_mallok(new_env, count_tab(data->shell.env) + 1);
      while (data->shell.env[j] != NULL)
	{
	  if (j == i && value == 2)
	    new_env[j] = my_strcpy_empty(data->parser.tab_args[1]);
	  if (j == i && value == 3)
	    new_env[j] = my_strcpy_full(data->parser.tab_args[1], data->parser.tab_args[2]);
	  if (j != i)
	    new_env[j] = my_strcpy(data->shell.env[j]);
	  j++;
	}
    }
  new_env = fill_env_none(data, i, &j, new_env);
  new_env[j] = NULL;
  my_free_tab(data->shell.env);
  return (new_env);
}

int		setenv_empty(t_data *data, int nb)
{
  if (data->shell.env == NULL)
    {
      data->shell.env = my_mallok(data->shell.env, 2);
      data->shell.env[0] = my_strcpy_empty(data->parser.tab_args[1]);
      data->shell.env[1] = NULL;
      return (SUCCESS);
    }
  data->shell.env = fill_env(data, nb);
  return (SUCCESS);
}

int		my_setenv(t_data *data)
{
  int		nb;

  nb = count_tab(data->parser.tab_args);
  if (nb > 3)
    return (ERROR);
  if (nb == 1)
    my_env(data);
  if (nb == 2 || nb == 3)
    if (setenv_empty(data, nb) == ERROR)
      return (ERROR);
  return (SUCCESS);
}
