/*
** exec_without_path.c for exec_without_path in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Sat Jun  4 11:20:59 2016 Hervé TCHIKLADZE
** Last update Sat Jun  4 11:23:17 2016 Hervé TCHIKLADZE
*/

#include "42sh.h"

int             exec_without_path_fork(t_data *data)
{
  pid_t         cpid;

  if ((cpid = fork()) == -1)
    return (ERROR);
  if (cpid == 0)
    {
      if (in_and_out(data) == ERROR)
        {
          exit(1);
          return (ERROR);
        }
      if (execve(data->parser.tab_args[0],				\
                 data->parser.tab_args, data->shell.env) == ERROR)
        bin_not_comp(data);
    }
  else
    if (father(cpid, data) == ERROR)
      return (ERROR);
  return (SUCCESS);
}

int             exec_without_path(t_data *data)
{
  char          *tmp;

  tmp = NULL;
  tmp = take_path_exec(data->parser.tab_args[0]);
  if ((access(tmp, F_OK | R_OK) == ERROR)
      || (((access(data->parser.tab_args[0], X_OK) == ERROR)) \
	  || (check_str_access(data->parser.tab_args[0]) == ERROR)))
    {
      tmp = my_free(tmp);
      return (error_not_found(data));
    }
  if (access(tmp, F_OK) == ERROR)
    {
      tmp = my_free(tmp);
      return (error_dir(data, data->parser.tab_args[0]));
    }
  tmp = my_free(tmp);
  if (exec_without_path_fork(data) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
