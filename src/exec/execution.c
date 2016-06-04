/*
** execution.c for excution in /home/payrau_a/rendu/aProjets/PSU/PSU_2015_42sh/src
** 
** Made by steeve payraudeau
** Login   <payrau_a@epitech.net>
** 
** Started on  Sat Jun  4 11:44:59 2016 steeve payraudeau
** Last update Sat Jun  4 11:45:01 2016 steeve payraudeau
*/

#include "42sh.h"

int		father(pid_t cpid, t_data *data)
{
  int		status;

  if (data->parser.check_pos_pipe != ALONE && \
      data->parser.check_pos_pipe != END)
    close(data->shell.fd[1]);
  if (data->shell.fd_db != 0)
    close(data->shell.fd_db != 0);
  if (waitpid(cpid, &status, WUNTRACED | WCONTINUED) == -1)
    return (ERROR);
  data->shell.exit_status = WEXITSTATUS(status);
  check_signal(data, status);
  return (SUCCESS);
}

int		exec_with_path(t_data *data, int i)
{
  pid_t		cpid;
  char		*tmp;

  tmp = NULL;
  if (i == -2)
    tmp = my_strcat("/bin", data->parser.tab_args[0], '/');
  else
    tmp = my_strcat(data->shell.path[i], data->parser.tab_args[0], '/');
  if ((cpid = fork()) == -1)
    return (ERROR);
  if (cpid == 0)
    {
      if (in_and_out(data) == ERROR)
	{
	  exit(1);
	  return (ERROR);
	}
      if (execve(tmp, data->parser.tab_args, data->shell.env) == ERROR)
	exit(1);
    }
  else
    father(cpid, data);
  my_free(tmp);
  return (SUCCESS);
}

int		execution(t_data *data)
{
  int		i;

  i = 0;
  if ((i = access_path(data)) != ERROR)
    {
      if (exec_with_path(data, i) == ERROR)
	{
	  data->shell.exit_status = 1;
	  return (ERROR);
	}
    }
  else
    {
      if (i == -2)
	return (ERROR);
      if (exec_without_path(data) == ERROR)
	{
	  data->shell.exit_status = 1;
	  return (ERROR);
	}
    }
  return (SUCCESS);
}
