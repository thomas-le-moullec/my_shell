/*
** my_builtins.c for my_builtins in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 16:27:00 2016 Thomas CHABOT
** Last update Tue Apr 26 18:38:59 2016 Thomas CHABOT
*/

#include "42sh.h"

int		my_builtins(t_data *data)
{
  static t_buil function[] = {{"exit", my_exit},
			      {"cd", my_cd},
			      {"env", my_env},
			      {"setenv", my_setenv},
			      {"unsetenv", my_unsetenv},
			      {NULL, NULL}};
  int		i;

  i = 0;
  while (function[i].name != NULL)
    {
      if (my_strcmp(data->parser.tab_args[0], function[i].name) == SUCCESS)
	{
	  if ((function[i].function)(data) == ERROR)
	    return (ERROR);
	  else
	    return (SUCCESS);
	}
      i++;
    }
  return (STOP);
}
