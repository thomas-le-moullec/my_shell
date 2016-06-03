/*
** my_where.c for my_where in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Thu Jun  2 13:38:03 2016 Thomas CHABOT
** Last update Fri Jun  3 10:31:24 2016 Thomas CHABOT
*/

#include "42sh.h"

int		check_where(char *tmp, int found)
{
  if (access(tmp, X_OK) == SUCCESS)
    {
      my_putstr(tmp, 1);
      my_putchar('\n', 1);
      found = 1;
    }
  return (found);
}

int		my_where_loop(t_data *data, int nb, char *tmp, int found)
{
  int		i;
  int		a;
  static int	b = 0;

  a = 1;
  while (nb-- > 1)
    {
      i = 0;
      b = 0;
      while (data->shell.path[i])
	{
	  tmp = NULL;
	  tmp = my_strcat(data->shell.path[i], data->parser.tab_args[a], '/');
          if (is_builtin(data, data->parser.tab_args[a]) == 2 && b == 0)
            {
              my_putstr(data->parser.tab_args[a], 1);
              my_putstr(" is a shell built-in\n", 1);
              b = 1;
            }
	  found = check_where(tmp, found);
	  i++;
	}
      a++;
    }
  return (found);
}

int		is_builtin(t_data *data, char *str)
{
  int		i;

  i = 0;
  while (i < 15)
    {
      if (my_strcmp(data->shell.tab_builtins[i], str) == SUCCESS)
	return (2);
      i++;
    }
  return (SUCCESS);
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
