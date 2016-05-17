/*
** execution.c for execution in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Wed May  4 16:03:28 2016 Thomas CHABOT
** Last update Mon May 16 10:57:57 2016 leo LE DIOURON
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
  if (!WIFEXITED(status))
    {
      data->shell.status = ERROR;
      my_putstr("Segmentation fault\n", 1);
    }
  return (SUCCESS);
}

int		exec_without_path(t_data *data)
{
  pid_t		cpid;

  if (access(data->parser.tab_args[0], X_OK) == ERROR || \
      ((data->parser.tab_args[0][0] != '.' &&		 \
       data->parser.tab_args[0][1] != '/') &&
       data->parser.tab_args[0][0] != '/'))
    {
      data->shell.status = ERROR;
      my_putstr(data->parser.tab_args[0], 1);
      my_putstr(": Command not found.\n", 1);
      return (ERROR);
    }
  if ((cpid = fork()) == -1)
    return (ERROR);
  if (cpid == 0)
    {
      if (in_and_out(data) == ERROR)
	return (ERROR);
      if (execve(data->parser.tab_args[0], \
		 data->parser.tab_args, data->shell.env) == ERROR)
	return (ERROR);
    }
  else
    father(cpid, data);
  return (SUCCESS);
}

int		exec_with_path(t_data *data, int i)
{
  pid_t		cpid;
  char		*tmp;

  tmp = NULL;
  tmp = my_strcat(data->shell.path[i], data->parser.tab_args[0], '/');
  if ((cpid = fork()) == -1)
    return (ERROR);
  if (cpid == 0)
    {
      if (in_and_out(data) == ERROR)
	return (ERROR);
      if (execve(tmp, data->parser.tab_args, data->shell.env) == -1)
	return (ERROR);
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
  if (data->shell.env == NULL || (my_strlen(data->parser.tab_args[0]) > 2 && \
      ((data->parser.tab_args[0][0] == '.' && \
	data->parser.tab_args[0][1] == '/') || \
       data->parser.tab_args[0][0] == '/')))
    return (ERROR);
  while (data->shell.path != NULL && data->shell.path[i] != NULL)
    {
      tmp = NULL;
      tmp = my_strcat(data->shell.path[i], data->parser.tab_args[0], '/');
      if (access(tmp, X_OK) == 0)
	{
	  my_free(tmp);
	  return (i);
	}
      my_free(tmp);
      i++;
    }
  return (ERROR);
}

int		execution(t_data *data)
{
  int		i;

  i = 0;
  data->shell.exit_status = 0;
  if ((i = access_path(data)) != ERROR)
    {
      if (exec_with_path(data, i) == ERROR)
	{
	  data->shell.exit_status = 1;
	  return (ERROR);
	}
    }
  else
    if (exec_without_path(data) == ERROR)
      {
	data->shell.exit_status = 1;
	return (ERROR);
      }
  return (SUCCESS);
}
