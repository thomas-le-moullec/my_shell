/*
** my_env.c for my_env in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 16:36:55 2016 Thomas CHABOT
** Last update Sat Jun  4 18:58:38 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static int		my_env_outfile(t_data *data)
{
  int			fd;

  if (data->parser.db_out == 0)
    {
      if ((fd = open(data->parser.outfile, \
		     O_CREAT | O_RDWR | O_TRUNC, S_IRWXU)) == -1)
	return (ERROR);
    }
  else
   {
     if ((fd = open(data->parser.outfile, \
		    O_CREAT | O_RDWR | O_APPEND, S_IRWXU)) == -1)
       return (ERROR);
   }
  return (fd);
}

static int		my_env_error(t_data *data)
{
  if (count_tab(data->parser.tab_args) > 1)
    {
      my_putstr("env: ", 1);
      my_putstr(data->parser.tab_args[1], 1);
      return (my_put_error(FOUND_ENV, 1));
    }
  return (SUCCESS);
}

int		my_env(t_data *data)
{
  int		fd;

  fd = 1;
  if ((my_env_error(data)) == ERROR)
    return (ERROR);
  if (data->parser.outfile != NULL \
      && (data->parser.check_pos_pipe == ALONE \
	  || data->parser.check_pos_pipe == END))
    if ((fd = my_env_outfile(data)) == ERROR)
      return (ERROR);
  if (data->parser.check_pos_pipe == MIDDLE \
      || data->parser.check_pos_pipe == BEGIN)
    fd = data->shell.fd[1];
  if (data->shell.env != NULL)
    my_show_env(data->shell.env, fd);
  if (fd != 1)
    close(fd);
  return (SUCCESS);
}
