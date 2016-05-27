/*
** pipe_loop.c for pipe_loop in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Wed May 25 10:01:19 2016 leo LE DIOURON
** Last update Wed May 25 10:06:42 2016 leo LE DIOURON
*/

#include "42sh.h"

void		pipe_alias(t_data *data, int i)
{
  int		a;

  a = 0;
  if (my_strncmp(data->parser.tab_pipe[i], "alias ", 6) != SUCCESS &&
      my_strncmp(data->parser.tab_pipe[i], "unalias ", 8) != SUCCESS)
    while (change_alias(data, i) == 1 && a < 2)
      a++;
}
