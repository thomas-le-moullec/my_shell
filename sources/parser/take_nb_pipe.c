/*
** take_nb_pipe.c for take_nb_pipe in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 18:19:34 2016 leo LE DIOURON
** Last update Sat Apr 30 13:59:04 2016 leo LE DIOURON
*/

#include "42sh.h"

void		take_nb_pipe(t_data *data)
{
  int		j;

  j = 1;
  data->parser.nb_pipe = my_mallok \
    (data->parser.nb_pipe, (count_tab(data->parser.tab_pipe) + 1) \
     * sizeof(int));
  data->parser.nb_pipe[0] = BEGIN;
  while (data->parser.tab_pipe[j] != NULL)
    {
      if (data->parser.tab_pipe[j + 1] == NULL)
	data->parser.nb_pipe[j] = END;
      else
	data->parser.nb_pipe[j] = MIDDLE;
      j++;
    }
  if (j == 1)
    data->parser.nb_pipe[0] = ALONE;
}