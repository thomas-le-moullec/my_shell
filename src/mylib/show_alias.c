/*
** show_alias.c for show_alias in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Mon May 23 15:08:34 2016 Hervé TCHIKLADZE
** Last update Wed Jun  1 23:49:50 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

void		show_alias(t_data *data)
{
  while (data->alias->prev != NULL)
    data->alias = data->alias->prev;
  while (data->alias->next != NULL)
    {
      my_putstr(SHOW_ALIAS, 1);
      my_putstr(data->alias->name, 1);
      my_putstr("='", 1);
      my_putstr(data->alias->cmd, 1);
      my_putstr("'\n", 1);
      data->alias = data->alias->next;
    }
  my_putstr(SHOW_ALIAS, 1);
  my_putstr(data->alias->name, 1);
  my_putstr("='", 1);
  my_putstr(data->alias->cmd, 1);
  my_putstr("'\n", 1);
  while (data->alias->next != NULL)
    data->alias = data->alias->next;
}
