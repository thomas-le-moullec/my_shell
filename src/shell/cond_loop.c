/*
** cond_loop.c for cond_loop in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Thu Jun  2 13:20:52 2016 leo LE DIOURON
** Last update Sat Jun  4 14:01:58 2016 leo LE DIOURON
*/

#include "42sh.h"

int		gestion_condition(t_data *data, int i)
{
  if (data->shell.exit_status != 0 && data->shell.cond[i] == AND)
    while (data->shell.cond[i] == AND)
      i++;
  if (data->shell.exit_status == 0 && data->shell.cond[i] == OR)
    while (data->shell.cond[i] == OR)
      i++;
  return (i);
}
