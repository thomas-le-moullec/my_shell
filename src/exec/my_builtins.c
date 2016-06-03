/*
** my_builtins.c for my_builtins in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Tue Apr 26 16:27:00 2016 Thomas CHABOT
** Last update Fri Jun  3 16:35:49 2016 leo LE DIOURON
*/

#include "42sh.h"

void		init_tab_builtins(t_data *data)
{
  data->shell.tab_builtins[0] = "alias";
  data->shell.tab_builtins[1] = "builtins";
  data->shell.tab_builtins[2] = "cd";
  data->shell.tab_builtins[3] = "echo";
  data->shell.tab_builtins[4] = "env";
  data->shell.tab_builtins[5] = "exit";
  data->shell.tab_builtins[6] = "history";
  data->shell.tab_builtins[7] = "repeat";
  data->shell.tab_builtins[8] = "set";
  data->shell.tab_builtins[9] = "setenv";
  data->shell.tab_builtins[10] = "unalias";
  data->shell.tab_builtins[11] = "unset";
  data->shell.tab_builtins[12] = "unsetenv";
  data->shell.tab_builtins[13] = "where";
  data->shell.tab_builtins[14] = "which";
}

int		show_builtins(t_data *data)
{
  int		i;

  i = 0;
  while (i < 15)
    {
      my_putstr(data->shell.tab_builtins[i], 1);
      my_putchar('\t', 1);
      i++;
    }
  my_putchar('\n', 1);
  return (SUCCESS);
}

int		my_builtins(t_data *data, int i)
{
  static t_buil function[] = {{"exit", my_exit}, {"cd", my_cd},
			      {"env", my_env}, {"setenv", my_setenv},
			      {"unsetenv", my_unsetenv}, {"echo", my_echo},
			      {"builtins", show_builtins},
			      {"alias", new_alias},{"unalias", unalias},
			      {"history", print_hist}, {"set", my_set},
			      {"unset", my_unset}, {"which", my_which},
			      {"where", my_where}, {NULL, NULL}};

  while (function[++i].name != NULL)
    if (my_strcmp(data->parser.tab_args[0], function[i].name) == SUCCESS)
      {
	if (i != 2 && i != 3 && i != 5 && data->parser.check_pos_pipe != ALONE
	    && data->parser.check_pos_pipe != END)
	  return (SUCCESS);
	if ((function[i].function)(data) == ERROR)
	  return (ERROR);
	else
	  {
	    data->shell.exit_status = 0;
	    return (SUCCESS);
	  }
      }
  return (STOP);
}
