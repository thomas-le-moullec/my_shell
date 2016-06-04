/*
** make_pipe.c for make_pipe in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 18:10:09 2016 leo LE DIOURON
** Last update Sat Jun  4 19:34:44 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

int		make_pipe(t_data *data)
{
  data->shell.save_fd = data->shell.fd[0];
  if (pipe(data->shell.fd) == -1)
    return (ERROR);
  if (data->shell.save_fd == 0)
    data->shell.save_fd = data->shell.fd[0];
  return (SUCCESS);
}
