/*
** my_which.c for my_which in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Thu Jun  2 13:38:52 2016 Thomas CHABOT
** Last update Sun Jun  5 14:48:17 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static int              check_which(t_data *data, char *tmp, int limit, int i)
{
  if (access(tmp, X_OK) == 0)
    {
      my_putstr(get_which(tmp), 1);
      my_putchar('\n', 1);
      limit = 1;
    }
  else
    if (i + 1 == count_tab(data->shell.path))
      {
        not_found_cmd(data, data->parser.tab_args[data->parser.pos]);
        limit = 1;
      }
  return (limit);
}

static int             my_which_check(t_data *data, char *tmp, \
				      int limit, int i)
{
  if (limit == 0)
    limit = check_which(data, tmp, limit, i);
  return (limit);
}

static void		which_core(t_data *data, char *tmp, int *b, int *limit)
{
  if ((*b = is_in_alias(data, tmp)) == 1)
    *limit = 1;
  if (is_builtin(data, data->parser.tab_args[data->parser.pos]) == 2	\
      && *b == 0)
    {
      *b = show_the_built(data->parser.tab_args[data->parser.pos], 1);
      *limit = 1;
    }
}

static void		my_which_loop(t_data *data, char *tmp, \
				      int nb, int limit)
{
  int			i;
  int			b;

  while (nb-- > 1 && limit == 0)
    {
      i = 0;
      b = 0;
      while (data->shell.path[i] && limit == 0)
	{
	  tmp = NULL;
	  tmp = my_strcat(data->shell.path[i++], \
			  data->parser.tab_args[data->parser.pos], '/');
	  which_core(data, tmp, &b, &limit);
	  if (b == 0)
	    limit = my_which_check(data, tmp, limit, i);
	  tmp = my_free(tmp);
	}
      if (nb > 1)
	limit = 0;
      data->parser.pos++;
    }
}

int		my_which(t_data *data)
{
  int		nb;
  char          *tmp;

  tmp = NULL;
  nb = count_tab(data->parser.tab_args);
  if (nb < 2)
    return (my_put_error(ERR_WHICH, 1));
  if (data->shell.path == NULL)
    return (ERROR);
  data->parser.pos = 1;
  my_which_loop(data, tmp, nb, 0);
  return (SUCCESS);
}
