/*
** exec.c for exec in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Tue Apr 26 16:23:05 2016 Thomas CHABOT
** Last update Fri Apr 29 14:10:57 2016 leo LE DIOURON
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
  if (execution(data) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
