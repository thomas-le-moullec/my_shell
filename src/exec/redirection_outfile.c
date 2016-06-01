/*
** redirection_outfile.c for redirection_outfile in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 16:40:08 2016 leo LE DIOURON
** Last update Wed Jun  1 11:41:43 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

int		redirection_outfile(t_data *data)
{
  int		fd;
  int		err;
  struct stat	s;

  err = 0;
  stat(data->parser.outfile, &s);
  if (data->parser.db_out == 0)
    if ((fd = open(data->parser.outfile,				\
		   O_CREAT | O_RDWR | O_TRUNC, S_IRWXU)) == ERROR)
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
  if (data->parser.db_out == 1)
    if ((fd = open(data->parser.outfile,				\
		   O_CREAT | O_RDWR | O_APPEND, S_IRWXU)) == ERROR)
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
  if (dup2(fd, 1) == ERROR)
    return (ERROR);
  close(fd);
  return (SUCCESS);
}
