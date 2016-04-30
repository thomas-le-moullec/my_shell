/*
** fill_env.c for fill_env in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sat Apr 30 16:26:26 2016 leo LE DIOURON
** Last update Sat Apr 30 16:31:40 2016 leo LE DIOURON
*/

#include "42sh.h"

char            **fill_env_none(t_data *data, char **new_env, int nb)
{
  int           j;

  j = 0;
  new_env = my_mallok(new_env, \
                      (count_tab(data->shell.env) + 2) * sizeof(char *));
  while (data->shell.env[j] != NULL)
    {
      new_env[j] = my_strcpy(data->shell.env[j]);
      j++;
    }
  if (nb == 3)
    new_env[j] = my_strcpy_full(data->parser.tab_args[1], \
                                data->parser.tab_args[2]);
  if (nb == 2)
    new_env[j] = my_strcpy_empty(data->parser.tab_args[1]);
  j++;
  new_env[j] = NULL;
  return (new_env);
}

char		**fill_env_loop(t_data *data, int value, char **new_env, int i)
{
  int		j;

  j = 0;
  new_env = my_mallok(new_env,						\
		      (count_tab(data->shell.env) + 1) * sizeof(char *));
  while (data->shell.env[j] != NULL)
    {
      if (j == i && value == 2)
	new_env[j] = my_strcpy_empty(data->parser.tab_args[1]);
      if (j == i && value == 3)
	new_env[j] = my_strcpy_full(data->parser.tab_args[1],		\
				    data->parser.tab_args[2]);
      if (j != i)
	new_env[j] = my_strcpy(data->shell.env[j]);
      j++;
    }
  new_env[j] = NULL;
  return (new_env);
}

char            **fill_env(t_data *data, int value)
{
  char          **new_env;
  int           i;

  new_env = NULL;
  if ((i = check_env_exist(data, data->parser.tab_args[1])) > 0)
    new_env = fill_env_loop(data, value, new_env, i);
  else
    new_env = fill_env_none(data, new_env, value);
  my_free_tab(data->shell.env);
  return (new_env);
}
