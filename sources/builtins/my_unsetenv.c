/*
** my_unsetenv.c for my_unsetenv in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 17:37:26 2016 Thomas CHABOT
** Last update Tue Apr 26 18:00:08 2016 Thomas CHABOT
*/

#include "42sh.h"

char		**unsetenv_loop(t_data* data, int i)
{
  char		**new_env;
  int		j;
  int		k;

  j = 0;
  k = 0;
  new_env = NULL;
  new_env = my_mallok(new_env, count_tab(data->shell.env));
  while (data->shell.env[j] != NULL)
    {
      if (j != i)
	new_env[k++] = my_strcpy(data->shell.env[j]);
      j++;
    }
  new_env[k] = NULL;
  my_free_tab(data->shell.env);
  return (new_env);
}

int		my_unsetenv(t_data *data)
{
  int		i;
  int		j;
  int		nb;

  i = 0;
  if ((nb = my_count_tab(data->parser.args)) <= 1)
    return (ERROR);
  while (i < nb - 1)
    {
      if ((j = check_env_exist(data, data->parser.args[i])) != ERROR)
	data->shell.env = unsetenv_loop(data, j);
      i++;
    }
  return (SUCCESS);
}
