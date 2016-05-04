/*
** take_type_cond.c for take_type_cond in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sat Apr 30 14:55:07 2016 leo LE DIOURON
** Last update Sun May  1 15:22:25 2016 leo LE DIOURON
*/

#include "42sh.h"

void		take_type_cond(t_data *data, int i)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  data->shell.cond = NULL;
  data->shell.cond = my_mallok\
    (data->shell.cond,(count_tab(data->parser.tab_cond) + 1) * sizeof(int));
  while (data->parser.tab_sep[i][x] != '\0')
    {
      data->shell.cond[y] = DEFAUT;
      if (data->parser.tab_sep[i][x] == '&' && \
	  data->parser.tab_sep[i][x + 1] == '&')
	{
	  data->shell.cond[y++] = AND;
	  x = x + 2;
	}
      if (data->parser.tab_sep[i][x] == '|' && \
	  data->parser.tab_sep[i][x + 1] == '|')
	{
	  data->shell.cond[y++] = OR;
	  x = x + 2;
	}
      if (data->parser.tab_sep[i][x] != '\0')
	x++;
    }
}
