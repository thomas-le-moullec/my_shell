/*
** exec.c for exec in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Tue Apr 26 16:23:05 2016 Thomas CHABOT
** Last update Fri Jun  3 16:36:10 2016 leo LE DIOURON
*/

#include "42sh.h"

int		check_str_access(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != '/' && str[i] != '.')
	return (SUCCESS);
      i++;
    }
  return (ERROR);
}

int		my_exec(t_data *data)
{
  int		i;

  i = 0;
  if (get_path(data) == ERROR)
    return (ERROR);
  while (i <= data->shell.nb_repeat)
    {
      data->shell.built = STOP;
      if ((data->shell.built = my_builtins(data, -1)) == ERROR)
	return (ERROR);
      if (data->shell.built != STOP && data->shell.nb_repeat == 0)
	return (STOP);
      data->shell.path = my_free_tab(data->shell.path);
      if (get_path(data) == ERROR)
	return (ERROR);
      if (my_strcmp(data->parser.tab_args[0], "echo") != SUCCESS)
	if (execution(data) == ERROR)
	  return (ERROR);
      i++;
    }
  return (SUCCESS);
}
