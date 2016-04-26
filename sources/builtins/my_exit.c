/*
** my_exit.c for my_exit in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 16:25:51 2016 Thomas CHABOT
** Last update Tue Apr 26 16:36:16 2016 Thomas CHABOT
*/

#include "42sh.h"

int		my_exit(t_data *data)
{
  int		nb;

  if (count_tab(data->parser.tab_args) > 2)
    return (ERROR);
  if (count_tab(data->parser.tab_args) == 1)
    exit(0);
  if ((nb = my_get_nbr(data->parser.tab_args[1])) == ERROR	\
      && my_strcmp(data->parser.tab_args[1], "-1") == ERROR)
    return (ERROR);
  exit(nb);
}
