/*
** my_check_which.c for my_check_which in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Sat Jun  4 13:19:19 2016 Thomas CHABOT
** Last update Sat Jun  4 13:19:54 2016 Thomas CHABOT
*/

#include "42sh.h"

int             check_which(t_data *data, char *tmp, int limit, int i)
{
  if (access(tmp, X_OK) == SUCCESS)
    {
      my_putstr(get_which(tmp), 1);
      my_putchar('\n', 1);
      limit = 1;
    }
  else
    if (i + 1 == count_tab(data->shell.path))
      {
	not_found_cmd(data, cut_str(tmp), i);
        limit = 1;
      }
  return (limit);
}

int             my_which_check(t_data *data, char *tmp, int limit, int i)
{
  if (limit == 0)
    limit = check_which(data, tmp, limit, i);
  return (limit);
}
