/*
** redirection_infile.c for redirection_infile in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 16:45:44 2016 leo LE DIOURON
** Last update Fri Apr 29 16:47:22 2016 leo LE DIOURON
*/

#include "42sh.h"

int     redirection_infile(t_data *data)
{
  int   fd;

  if (data->parser.db_in == 0)
    {
      if ((fd = open(data->parser.infile, O_RDONLY)) == ERROR)
	return (ERROR);
      if (dup2(fd, 0) == ERROR)
        return (ERROR);
      close(fd);
    }
  return (SUCCESS);
}
