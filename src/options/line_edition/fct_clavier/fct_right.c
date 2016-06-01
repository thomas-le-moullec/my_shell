/*
** fct_right.c for right in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh/sources/options/fct_clavier
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 17:21:48 2016 Hervé TCHIKLADZE
** Last update Wed Jun  1 17:08:01 2016 steeve payraudeau
*/

#include "42sh.h"

int		fct_right(t_data *data, int *i)
{
  if ((*i) < my_strlen(data->shell.line))
    {
      (*i) += 1;
      my_putstr(tgetstr("nd", NULL), 1);
    }
  return (SUCCESS);
}
