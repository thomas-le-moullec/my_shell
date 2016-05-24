/*
** my_setenv.c for my_setenv in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 16:40:35 2016 Thomas CHABOT
** Last update Tue May 24 13:24:42 2016 Thomas CHABOT
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
    return (my_put_error(ER_SETENV, 1));
  if (nb == 1)
    my_env(data);
  if (nb == 2 || nb == 3)
    if (setenv_empty(data, nb) == ERROR)
      return (ERROR);
  return (SUCCESS);
}
