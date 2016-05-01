/*
** redirection_infile.c for redirection_infile in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 16:45:44 2016 leo LE DIOURON
** Last update Sun May  1 14:41:17 2016 leo LE DIOURON
*/

#include "42sh.h"

int		double_infile_redir(t_data *data)
{
  char		*str;
  char		*result;

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
  dup2(0, 1);
  my_putstr(result, 1);
  dup2(1, 0);
  return (SUCCESS);
}

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
  else
    if (double_infile_redir(data) == ERROR)
      return (ERROR);
  return (SUCCESS);
}
