/*
** execution.c for execution in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Wed May  4 16:03:28 2016 Thomas CHABOT
** Last update Wed Jun  1 09:42:37 2016 Thomas LE MOULLEC
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

int		exec_without_path(t_data *data)
{
  pid_t		cpid;

  if ((access(take_path_exec(data->parser.tab_args[0]), F_OK | R_OK) == ERROR)
      || (((access(data->parser.tab_args[0], X_OK) == ERROR)) \
      || (check_str_access(data->parser.tab_args[0]) == ERROR)))
    return (error_not_found(data));
  if (access(data->parser.tab_args[0], F_OK) == ERROR)
    return (error_dir(data, data->parser.tab_args[0]));
  if ((cpid = fork()) == -1)
    return (ERROR);
  if (cpid == 0)
    {
      if (in_and_out(data) == ERROR)
	{
	  exit(1);
	  return (ERROR);
	}
      if (execve(data->parser.tab_args[0], \
		 data->parser.tab_args, data->shell.env) == ERROR)
	  exit(1);
    }
  else
    if (father(cpid, data) == ERROR)
      return (ERROR);
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

int		access_path(t_data *data)
{
  int		i;
  char		*tmp;

  i = 0;
  if (access_path_file(data) != SUCCESS)
    return (error_perm(data));
  if (access_path_er(data) == ERROR)
    return (ERROR);
  while (data->shell.path != NULL && data->shell.path[i] != NULL)
    {
      tmp = NULL;
      tmp = my_strcat(data->shell.path[i], data->parser.tab_args[0], '/');
      if (access(tmp, X_OK | F_OK | R_OK) == 0)
	{
	  my_free(tmp);
	  return (i);
	}
      tmp = my_free(tmp);
      i++;
    }
  tmp = NULL;
  tmp = my_strcat("/bin", data->parser.tab_args[0], '/');
  if (data->shell.bin == 1 && access(tmp, X_OK | F_OK | R_OK) == 0)
    {
      tmp = my_free(tmp);
      return (-2);
    }
  tmp = my_free(tmp);
  return (ERROR);
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
