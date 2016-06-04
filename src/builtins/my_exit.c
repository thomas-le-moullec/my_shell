/*
** my_exit.c for my_exit in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 16:25:51 2016 Thomas CHABOT
** Last update Sat Jun  4 19:01:09 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static int	check_exit(t_data *data)
{
  if (count_tab(data->parser.tab_args) > 2)
    return (my_put_error(EXIT_FAIL, 1));
  if (count_tab(data->parser.tab_args) == 1)
    {
      if (isatty(0) != 0)
	if ((mode_canon(1)) == ERROR)
	  return (ERROR);
      end_fct(data);
      exit(0);
    }
  return (SUCCESS);
}

int		my_exit(t_data *data)
{
  int		nb;

  if (check_exit(data) == ERROR)
    return (ERROR);
  if ((nb = my_getnbr(data->parser.tab_args[1])) == ERROR \
      && my_strcmp(data->parser.tab_args[1], "-1") == ERROR)
    return (my_put_error(EXIT_FAIL, 1));
  if (isatty(0) != 0)
    if ((mode_canon(1)) == ERROR)
      return (ERROR);
  end_fct(data);
  exit(nb);
}
