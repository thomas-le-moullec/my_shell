/*
** redirection_outfile.c for redirection_outfile in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 16:40:08 2016 leo LE DIOURON
** Last update Sat Jun  4 19:38:55 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static int             err_redir_outfile(t_data *data, int err)
{
  err = errno;
  my_putstr(data->parser.outfile, 1);
  if (err == ENOTDIR)
    return (my_put_error(NOT_DIR, 1));
  if (err == EACCES)
    return (my_put_error(PERM_DENIED, 1));
  if (err == ENOENT)
    return (my_put_error(FOUND_DIR, 1));
  return (my_put_error(IS_DIR, 1));
}

static int             err_db_redir_outfile(t_data *data, int err)
{
  err = errno;
  my_putstr(data->parser.outfile, 1);
  if (err == ENOTDIR)
    return (my_put_error(NOT_DIR, 1));
  if (err == EACCES)
    return (my_put_error(PERM_DENIED, 1));
  if (err == ENOENT)
    return (my_put_error(FOUND_DIR, 1));
  return (my_put_error(IS_DIR, 1));
}

int		redirection_outfile(t_data *data)
{
  int		fd;
  int		err;
  struct stat	s;

  err = 0;
  stat(data->parser.outfile, &s);
  if (data->parser.db_out == 0)
    if ((fd = open(data->parser.outfile, \
		   O_CREAT | O_RDWR | O_TRUNC, S_IRWXU)) == -1)
      return (err_redir_outfile(data, err));
  if (data->parser.db_out == 1)
    if ((fd = open(data->parser.outfile, \
		   O_CREAT | O_RDWR | O_APPEND, S_IRWXU)) == -1)
      return (err_db_redir_outfile(data, err));
  if (dup2(fd, 1) == -1)
    return (ERROR);
  close(fd);
  return (SUCCESS);
}
