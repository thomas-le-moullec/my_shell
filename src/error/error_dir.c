/*
** error_dir.c for error_dir in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Fri May 20 13:32:31 2016 Hervé TCHIKLADZE
** Last update Fri May 20 13:36:06 2016 Hervé TCHIKLADZE
*/

#include "42sh.h"

int		error_not_found(t_data *data)
{
  data->shell.status = ERROR;
  my_putstr(data->parser.tab_args[0], 1);
  my_putstr(": Command not found.\n", 1);
  return (ERROR);
}

int		error_dir(t_data *data)
{
  my_putstr(data->parser.tab_args[0], 1);
  my_putstr(": Not a directory.\n", 1);
  return (ERROR);
}

int		error_perm(t_data *data)
{
  my_putstr(data->parser.tab_args[0], 1);
  my_putstr(": Permissions denied.\n", 1);
  return (ERROR);
}
