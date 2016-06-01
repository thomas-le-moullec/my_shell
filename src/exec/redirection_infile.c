/*
** redirection_infile.c for redirection_infile in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 16:45:44 2016 leo LE DIOURON
** Last update Wed Jun  1 11:43:36 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

int		double_infile_redir(t_data *data)
{
  char		*str;
  char		*result;
  int		fd;

  if ((fd = open("/tmp/tempo42", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU)) == ERROR)
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

int		redirection_infile(t_data *data)
{
  int		fd;
  int           err;
  struct stat   s;

  if (data->parser.db_in == 0)
    {
      printf("..%s..\n", data->parser.infile);
      stat(data->parser.infile, &s);


      if ((fd = open(data->parser.infile, O_RDONLY)) == ERROR)
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
    }
  else
    {
      if (double_infile_redir(data) == ERROR)
	return (ERROR);
      if ((fd = open("/tmp/tempo42", O_RDONLY)) == ERROR)
        return (ERROR);
      if (dup2(fd, 0) == -1)
        return (ERROR);
      close(fd);
    }
  return (SUCCESS);
}
