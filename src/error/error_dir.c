/*
** error_dir.c for error_dir in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Fri May 20 13:32:31 2016 Hervé TCHIKLADZE
** Last update Mon May 30 10:46:27 2016 Thomas CHABOT
*/

#include "42sh.h"

int		error_not_found(t_data *data)
{
  my_putstr(data->parser.tab_args[0], 1);
  my_putstr(NOT_FOUND, 1);
  data->shell.exit_status = 1;
  return (ERROR);
}

int		error_dir(t_data *data, char *str)
{
  my_putstr(str, 1);
  my_putstr(NOT_DIR, 1);
  data->shell.exit_status = 1;
  return (ERROR);
}

int		error_perm(t_data *data)
{
  my_putstr(data->parser.tab_args[0], 1);
  my_putstr(PERM_DENIED, 1);
  data->shell.exit_status = 1;
  return (-2);
}
