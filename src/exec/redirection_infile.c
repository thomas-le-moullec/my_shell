/*
** redirection_infile.c for redirection_infile in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 16:45:44 2016 leo LE DIOURON
** Last update Sat Jun  4 19:37:30 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static int		double_infile_redir(t_data *data)
{
  char			*str;
  char			*result;
  int			fd;

  str = NULL;
  if ((fd = open("/tmp/tempo42", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU))
      == -1)
    return (ERROR);
  my_putstr("? ", 1);
  if ((str = get_next_line(0)) == NULL)
    return (ERROR);
  result = my_strcpy(str);
  while (my_strcmp(str, data->parser.infile) != SUCCESS)
    {
      my_putstr("? ", 1);
      if ((str = get_next_line(0)) == NULL)
	return (ERROR);
      if (my_strcmp(str, data->parser.infile) != SUCCESS)
	result = my_strcat(result, str, '\n');
    }
  result = my_strcat(result, "\0", '\n');
  my_putstr(result, fd);
  return (SUCCESS);
}

static int		infile_simple(t_data *data)
{
  int			err;
  int			fd;
  struct stat		s;

  stat(data->parser.infile, &s);
  if ((fd = open(data->parser.infile, O_RDONLY)) == -1)
    {
      err = errno;
      my_putstr(data->parser.infile, 1);
      if (err == ENOTDIR)
	return (my_put_error(NOT_DIR, 1));
      if (err == EACCES)
	return (my_put_error(PERM_DENIED, 1));
      if (err == ENOENT)
	return (my_put_error(FOUND_DIR, 1));
      return (my_put_error(IS_DIR, 1));
    }
  if (dup2(fd, 0) == -1)
    return (ERROR);
  close(fd);
  return (SUCCESS);
}

int		redirection_infile(t_data *data)
{
  int		fd;

  if (data->parser.db_in == 0)
    {
      if (infile_simple(data) == ERROR)
	return (ERROR);
    }
  else
    {
      if (double_infile_redir(data) == ERROR)
	return (ERROR);
      if ((fd = open("/tmp/tempo42", O_RDONLY)) == -1)
        return (ERROR);
      if (dup2(fd, 0) == -1)
        return (ERROR);
      close(fd);
    }
  return (SUCCESS);
}
