/*
** execution.c for execution in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 13:30:09 2016 leo LE DIOURON
** Last update Sat Apr 30 16:11:33 2016 leo LE DIOURON
*/

#include "42sh.h"

void		father(pid_t cpid, t_data *data)
{
  int		status;

  if (data->parser.check_pos_pipe != ALONE && \
      data->parser.check_pos_pipe != END)
    close(data->shell.fd[1]);
  waitpid(cpid, &status, WUNTRACED | WCONTINUED);
  if (!WIFEXITED(status))
    {
      data->shell.status = ERROR;
      my_putstr("Segmentation fault\n", 1);
    }
}

int		exec_without_path(t_data *data)
{
  pid_t		cpid;

  if (access(data->parser.tab_args[0], X_OK) == ERROR && \
      ((data->parser.tab_args[0][0] != '.' &&		 \
       data->parser.tab_args[0][1] != '/') ||
       data->parser.tab_args[0][0] != '/'))
    {
      data->shell.status = ERROR;
      my_putstr(data->parser.tab_args[0], 1);
      my_putstr(": Command not found.\n", 1);
      return (ERROR);
    }
  cpid = fork();
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
  cpid = fork();
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
  while (data->shell.path[i] != NULL)
    {
      tmp = NULL;
      tmp = my_strcat(data->shell.path[i], data->parser.tab_args[0], '/');
      if (access(tmp, X_OK) == SUCCESS)
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
  if ((i = access_path(data)) != ERROR)
    {
      if (exec_with_path(data, i) == ERROR)
	return (ERROR);
    }
  else
    if (exec_without_path(data) == ERROR)
      return (STOP);
  return (SUCCESS);
}
