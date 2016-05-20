/*
** redirection_outfile.c for redirection_outfile in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 16:40:08 2016 leo LE DIOURON
** Last update Fri Apr 29 16:45:00 2016 leo LE DIOURON
*/

#include "42sh.h"

int	redirection_outfile(t_data *data)
{
  int   fd;

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
  if (dup2(fd, 1) == ERROR)
    return (ERROR);
  close(fd);
  return (SUCCESS);
}
