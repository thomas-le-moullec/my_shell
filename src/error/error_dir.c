/*
** error_dir.c for error_dir in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Fri May 20 13:32:31 2016 Hervé TCHIKLADZE
** Last update Sun Jun  5 16:12:29 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

int		error_not_found(t_data *data)
{
  int		i;

  i = 0;
  while (i <= data->shell.nb_repeat)
    {
      my_putstr(data->parser.tab_args[0], 1);
      my_putstr(NOT_FOUND, 1);
      i++;
    }
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
