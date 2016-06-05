/*
** my_where.c for my_where in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Thu Jun  2 13:38:03 2016 Thomas CHABOT
** Last update Sun Jun  5 14:18:25 2016 Thomas CHABOT
*/

#include "42sh.h"

static int		check_where(char *tmp)
{
  if (access(tmp, X_OK) == 0)
    {
      my_putstr(tmp, 1);
      my_putchar('\n', 1);
    }
  return (SUCCESS);
}

static int		my_where_loop(t_data *data, int nb, char *tmp, int a)
{
  int			i;
  int			b;

  while (nb-- > 1)
    {
      i = 0;
      b = 0;
      while (data->shell.path[i])
	{
	  tmp = NULL;
	  tmp = my_strcat(data->shell.path[i], data->parser.tab_args[a], '/');
	  if (b == 0)
	    b = is_in_alias(data, tmp);
          if (is_builtin(data, data->parser.tab_args[a]) == 2 && b == 0)
	    b = show_the_built(data->parser.tab_args[a], 2);
	  if (is_builtin(data, data->parser.tab_args[a]) != 2)
	    check_where(tmp);
	  i++;
	  tmp = my_free(tmp);
	}
      a++;
    }
  return (SUCCESS);
}

int		my_where(t_data *data)
{
  int		nb;
  char		*tmp;

  tmp = NULL;
  nb = count_tab(data->parser.tab_args);
  if (nb < 2)
    return (my_put_error(ERR_WHERE, 1));
  if (data->shell.path == NULL)
    return (ERROR);
  my_where_loop(data, nb, tmp, 1);
  return (SUCCESS);
}
