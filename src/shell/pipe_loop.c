/*
** pipe_loop.c for pipe_loop in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Wed May 25 10:01:19 2016 leo LE DIOURON
** Last update Sat Jun  4 20:52:31 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static void		pipe_alias(t_data *data, int i)
{
  int		a;

  a = 0;
  if (my_strncmp(data->parser.tab_pipe[i], "alias ", 6) != SUCCESS &&
      my_strncmp(data->parser.tab_pipe[i], "unalias ", 8) != SUCCESS)
    while (change_alias(data, i) == 1 && a < 2)
      a++;
}

int		modify_str_pipe(t_data *data, int i)
{
  if (data->parser.quote != 2)
    {
      if (var_env_loc(data, i) == ERROR)
	return (STOP);
      pipe_alias(data, i);
      if (modif_args_hist(data, i) == ERROR)
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
