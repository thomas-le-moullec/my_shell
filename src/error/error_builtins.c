/*
** error_builtins.c for error_builtins in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Mon May 16 14:34:21 2016 Thomas CHABOT
** Last update Mon May 30 18:32:38 2016 Thomas CHABOT
*/

#include "42sh.h"

int		error_denied(t_data *data, char *str)
{
  my_putstr(str, 1);
  my_putstr(": Permission denied.\n", 1);
  data->shell.exit_status = 1;
  return (ERROR);
}

void		error_no_file(t_data *data, char *str)
{
  my_putstr(str, 1);
  my_putstr(": No such file or directory.\n", 1);
  data->shell.exit_status = 1;
}

int		error_alpha(t_data *data, int flag)
{
  if (flag == 1)
    my_putstr("setenv: Variable name must begin with a letter.\n", 1);
  if (flag == 2)
    my_putstr("setenv: Variable name must contain alphanumeric characters.\n", 1);
  data->shell.exit_status = 1;
  return (ERROR);
}

int		error_event(t_data *data, char *str)
{
  my_putstr(str, 1);
  my_putstr(": Event not found.\n", 1);
  data->shell.exit_status = 1;
  return (ERROR);
}
