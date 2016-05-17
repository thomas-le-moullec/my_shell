/*
** check_all_access.c for check_all_access in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri May  6 10:35:51 2016 leo LE DIOURON
** Last update Fri May  6 10:46:24 2016 leo LE DIOURON
*/

#include "42sh.h"

int		exist_exec(char *str, t_data *data)
{
  return (SUCCESS);
}

int		check_all_access(t_data *data)
{
  int		j;
  int		ok;
  char		*tmp;

  ok = SUCCESS;
  while (data->shell.tab_pipe[j] != NULL)
    {
      tmp = take_first(data->shell.tab_pipe[j]);
      if (exist_exec(tmp) == ERROR)
	{
	  data->shell.status = ERROR;
	  my_putstr(data->parser.tab_args[0], 1);
	  my_putstr(": Command not found.\n", 1);
	  ok = ERROR;
	}
      j++;
    }
  if (ok == ERROR)
    return (ERROR);
  return (SUCCESS);
}
