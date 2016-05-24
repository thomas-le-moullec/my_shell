/*
** my_builtins.c for my_builtins in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Tue Apr 26 16:27:00 2016 Thomas CHABOT
** Last update Mon May 23 17:58:36 2016 Thomas CHABOT
*/

#include "42sh.h"

int		show_builtins(t_data *data)
{
  (void)data;
  my_putstr("builtins\t", 1);
  my_putstr("\tcd", 1);
  my_putstr("\tenv", 1);
  my_putstr("\texit", 1);
  my_putstr("\tsetenv", 1);
  my_putstr("\tunsetenv\n", 1);
  return (SUCCESS);
}

int		my_builtins(t_data *data)
{
  static t_buil function[] = {{"exit", my_exit}, {"cd", my_cd},
			      {"env", my_env}, {"setenv", my_setenv},
			      {"unsetenv", my_unsetenv},
			      {"builtins", show_builtins},
			      {NULL, NULL}};
  int		i;

  i = 0;
  while (function[i].name != NULL)
    {
      if (my_strcmp(data->parser.tab_args[0], function[i].name) == SUCCESS)
	{
	  if (i != 2 && i != 3 && \
	      data->parser.check_pos_pipe != ALONE && \
	      data->parser.check_pos_pipe != END)
	    return (SUCCESS);
	  if ((function[i].function)(data) == ERROR)
	    return (ERROR);
	  else
	    {
	      data->shell.exit_status = 0;
	      return (SUCCESS);
	    }
	}
      i++;
    }
  return (STOP);
}
