/*
** my_where.c for my_where in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Thu Jun  2 13:38:03 2016 Thomas CHABOT
** Last update Thu Jun  2 19:44:45 2016 Thomas CHABOT
*/

#include "42sh.h"

int		my_where_loop(t_data *data, int nb, char *tmp, int found)
{
  int		i;
  int		a;

  a = 1;
  while (nb-- > 1)
    {
      i = 0;
      while (data->shell.path[i])
	{
	  tmp = NULL;
	  tmp = my_strcat(data->shell.path[i], data->parser.tab_args[a], '/');
	  if (access(tmp, X_OK) == SUCCESS)
	    {
	      my_putstr(tmp, 1);
	      my_putchar('\n', 1);
	      found = 1;
	    }
	  i++;
	}
      a++;
    }
  return (found);
}

int		my_where(t_data *data)
{
  int		nb;
  char		*tmp;
  int		found;

  found = 0;
  tmp = NULL;
  nb = count_tab(data->parser.tab_args);
  if (nb < 2)
    return (my_put_error(ERR_WHERE, 1));
  if (data->shell.path == NULL)
    return (ERROR);
  found = my_where_loop(data, nb, tmp, found);
  if (found == 0)
    return (not_found_cmd(data));
  return (SUCCESS);
}
