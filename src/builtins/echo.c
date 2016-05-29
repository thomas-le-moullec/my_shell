/*
** echo.c for echo in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Tue May 24 13:09:26 2016 leo LE DIOURON
** Last update Sun May 29 14:11:34 2016 steeve payraudeau
*/

#include "42sh.h"

void		my_putstr_echo(t_data *data, char *str, int fd)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != '\\' && data->parser.quote == 0)
	my_putchar(str[i], fd);
      if (data->parser.quote == 1)
	{
	  if (str[i] == '\\' && str[i + 1] == 'n')
	    {
	      i++;
	      my_putchar('\n', fd);
	      if (str[i] == '\0')
		return ;
	    }
	  else
	    my_putchar(str[i], fd);
	}
      i++;
    }
}

int             my_echo_outfile(t_data *data)
{
  int           fd;

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

int		take_fd_echo(t_data *data)
{
  int		fd;

  fd = 1;
  if (data->parser.outfile != NULL
      && (data->parser.check_pos_pipe == ALONE
          || data->parser.check_pos_pipe == END))
    if ((fd = my_echo_outfile(data)) == ERROR)
      return (ERROR);
  if (data->parser.check_pos_pipe == MIDDLE
      || data->parser.check_pos_pipe == BEGIN)
    fd = data->shell.fd[1];
  return (fd);
}

int	my_echo(t_data *data)
{
  int	j;
  int	n;
  int	fd;

  j = 1;
  n = 0;
  if ((fd = take_fd_echo(data)) == ERROR)
    return (ERROR);
  if (data->parser.tab_args[1] != NULL && \
      my_strcmp(data->parser.tab_args[1], "-n") == SUCCESS)
    {
      n = 1;
      j++;
    }
  while (data->parser.tab_args[j] != NULL)
    {
      my_putstr_echo(data, data->parser.tab_args[j++], fd);
      if (data->parser.tab_args[j] != NULL)
	my_putchar(' ', fd);
    }
  if (n == 0)
    my_putchar('\n', fd);
  if (fd != 1)
    close(fd);
  return (SUCCESS);
}
