/*
** error_bin.c for error_bin in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Jun  3 16:38:05 2016 leo LE DIOURON
** Last update Fri Jun  3 17:10:48 2016 leo LE DIOURON
*/

#include "42sh.h"

void	bin_not_comp(t_data *data)
{
  my_putstr(data->parser.tab_args[0], 1);
  my_putstr(EXEC_ERROR, 1);
  exit(1);
}
