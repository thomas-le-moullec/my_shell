/*
** pipe_loop.c for pipe_loop in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Wed May 25 10:01:19 2016 leo LE DIOURON
** Last update Sun Jun  5 13:24:51 2016 leo LE DIOURON
*/

#include "42sh.h"

static void		pipe_alias(t_data *data, int i)
{
  data->shell.alias_loop = 0;
  if (my_strncmp(data->parser.tab_pipe[i], "alias ", 6) != SUCCESS &&
      my_strncmp(data->parser.tab_pipe[i], "unalias ", 8) != SUCCESS)
    while (change_alias(data, i) == 1 && data->shell.alias_loop == 0);
  if (data->alias != NULL)
    {
      while (data->alias->prev != NULL)
	{
	  data->alias->flag = 0;
	  data->alias = data->alias->prev;
	}
      data->alias->flag = 0;
      while (data->alias->next != NULL)
	data->alias = data->alias->next;
    }
  if (data->shell.alias_loop == 1)
    data->shell.exit_status = 1;
}

int		modify_str_pipe(t_data *data, int i)
{
  if (data->parser.quote != 2)
    {
      if (var_env_loc(data, i) == ERROR)
	return (STOP);
      pipe_alias(data, i);
      if (data->shell.alias_loop == 1 || modif_args_hist(data, i) == ERROR)
	return (STOP);
    }
  return (SUCCESS);
}

int		modify_inhib_glob_pipe(t_data *data)
{
  if (args_convert(data) == STOP)
    return (STOP);
  if (data->shell.chk_magic == 0 && data->parser.quote == 0)
    if (my_glob(data) == ERROR)
      return (STOP);
  return (SUCCESS);
}
