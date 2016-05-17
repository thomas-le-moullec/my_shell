/*
** my_env.c for my_env in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 16:36:55 2016 Thomas CHABOT
** Last update Wed May  4 16:06:15 2016 Thomas CHABOT
*/

#include "42sh.h"

int		my_env_outfile(t_data *data)
{
  int		fd;

  if (data->parser.db_out == 0)
    {
      if ((fd = open(data->parser.outfile, \
		     O_CREAT | O_RDWR | O_TRUNC, S_IRWXU)) == ERROR)
	return (ERROR);
    }
  else
   {
     if ((fd = open(data->parser.outfile, \
		    O_CREAT | O_RDWR | O_APPEND, S_IRWXU)) == ERROR)
       return (ERROR);
   }
  return (fd);
}

int		my_env(t_data *data)
{
  int		fd;

  fd = 1;
  if (data->parser.outfile != NULL
      && (data->parser.check_pos_pipe == ALONE
	  || data->parser.check_pos_pipe == END))
    if ((fd = my_env_outfile(data)) == ERROR)
      return (ERROR);
  if (data->parser.check_pos_pipe == MIDDLE
      || data->parser.check_pos_pipe == BEGIN)
    fd = data->shell.fd[1];
  if (data->shell.env != NULL)
    my_show_env(data->shell.env, fd);
  if (fd != 1)
    close(fd);
  return (SUCCESS);
}
