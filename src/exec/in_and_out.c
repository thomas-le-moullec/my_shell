/*
** in_and_out.c for in_and_out in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
**
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
**
** Started on  Fri Apr 29 17:57:25 2016 leo LE DIOURON
** Last update Sat Jun  4 19:34:15 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static int		manage_all_redir(t_data *data)
{
  if (data->parser.outfile != NULL && \
      (data->parser.check_pos_pipe == ALONE || \
       data->parser.check_pos_pipe == END))
    if (redirection_outfile(data) == ERROR)
      return (ERROR);
  if (data->parser.infile != NULL && \
      (data->parser.check_pos_pipe == ALONE || \
       data->parser.check_pos_pipe == BEGIN))
    if (redirection_infile(data) == ERROR)
      return (ERROR);
  return (SUCCESS);
}

static int		manage_pipe(t_data *data)
{
  if (data->parser.check_pos_pipe != ALONE && \
      data->parser.check_pos_pipe != END)
    {
      close(data->shell.fd[0]);
      if (dup2(data->shell.fd[1], 1) == -1)
	return (ERROR);
    }
  if (data->parser.check_pos_pipe != ALONE && \
      data->parser.check_pos_pipe != BEGIN)
    {
      close(data->shell.fd[1]);
      if (dup2(data->shell.save_fd, 0) == -1)
	return (ERROR);
    }
  return (SUCCESS);
}

int		in_and_out(t_data *data)
{
  if (manage_all_redir(data) == ERROR)
    return (ERROR);
  if (manage_pipe(data) == ERROR)
    return (STOP);
  return (SUCCESS);
}
