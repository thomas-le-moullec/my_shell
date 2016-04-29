/*
** exec.c for exec in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Tue Apr 26 16:23:05 2016 Thomas CHABOT
** Last update Wed Apr 27 16:08:16 2016 Thomas CHABOT
*/

#include "42sh.h"

int		my_exec(t_data *data)
{
  data->shell.built = STOP;
  if ((data->shell.built = my_builtins(data)) == ERROR)
    return (ERROR);
  if (data->shell.built != STOP)
    return (STOP);
  if (get_path(data) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
