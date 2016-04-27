/*
** exec.c for exec in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Tue Apr 26 16:23:05 2016 Thomas CHABOT
** Last update Tue Apr 26 18:40:01 2016 Thomas CHABOT
*/

#include "42sh.h"

int		exec(t_data *data)
{
  data->parser.built = STOP;
  if ((data->parser.built = my_builtins(data)) == ERROR)
    return (ERROR);
  if (data->parser.built != STOP)
    return (STOP);
  if (get_path(data) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
