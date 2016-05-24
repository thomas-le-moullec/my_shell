/*
** error_builtins.c for error_builtins in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Mon May 16 14:34:21 2016 Thomas CHABOT
** Last update Tue May 24 11:20:24 2016 Thomas CHABOT
*/

#include "42sh.h"

int		error_unsetenv()
{
  write(1, "unsetenv: Too few arguments.\n", 29);
  return (ERROR);
}

int		error_setenv()
{
  write(1, "setenv: Too many arguments.\n", 28);
  return (ERROR);
}

void		error_denied(t_data *data, char *str)
{
  my_putstr(str, 1);
  my_putstr(": Permission denied.\n", 1);
  data->shell.exit_status = 1;
}

void		error_no_file(t_data *data, char *str)
{
  my_putstr(str, 1);
  my_putstr(": No such file or directory.\n", 1);
  data->shell.exit_status = 1;
}
