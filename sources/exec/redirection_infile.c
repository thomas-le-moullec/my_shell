/*
** redirection_infile.c for redirection_infile in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 16:45:44 2016 leo LE DIOURON
** Last update Wed May  4 17:06:30 2016 Thomas CHABOT
*/

#include "42sh.h"

int		double_infile_redir(t_data *data)
{
  char		*str;
  char		*result;
  pid_t		cpid;
  int		status;

  if ((data->shell.fd_db = dup(data->shell.fd_db)) == -1)
    return (ERROR);
  if ((cpid = fork()) == -1)
    return (ERROR);
  if (cpid == 0)
    {
      if (dup2(data->shell.fd_db, 0) == -1)
	return (ERROR);
      my_putstr("? ", 1);
      if ((str = get_next_line()) == NULL)
	return (ERROR);
      result = my_strcpy(str);
      while (my_strcmp(str, data->parser.infile) != SUCCESS)
	{
	  my_putstr("? ", 1);
	  if ((str = get_next_line()) == NULL)
	    return (ERROR);
	  result = my_strcat(result, str, '\n');
	}
      my_putstr(result, data->shell.fd_db);
      exit(0);
    }
  else
    if (waitpid(cpid, &status, WUNTRACED | WCONTINUED) == -1)
      return (ERROR);
  return (SUCCESS);
}

int     redirection_infile(t_data *data)
{
  int   fd;

  if (data->parser.db_in == 0)
    {
      if ((fd = open(data->parser.infile, O_RDONLY)) == -1)
	return (ERROR);
      if (dup2(fd, 0) == -1)
        return (ERROR);
      close(fd);
    }
  else
    if (double_infile_redir(data) == ERROR)
      return (ERROR);
  return (SUCCESS);
}
