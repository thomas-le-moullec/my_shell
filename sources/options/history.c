/*
** history.c for history in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 16:05:48 2016 Hervé TCHIKLADZE
** Last update Wed May 18 16:25:01 2016 Thomas CHABOT
*/

#include "42sh.h"

t_hist		*add_elem_key(t_hist *list, char *str)
{
  t_hist	*new_elem;

  new_elem = NULL;
  new_elem = my_mallok(new_elem, sizeof(*new_elem));
  new_elem->str = my_strcpy(str);
  if (list == NULL)
    {
      new_elem->prev = NULL;
      new_elem->next = NULL;
      new_elem->pos = 1;
      return (new_elem);
    }
  new_elem->pos = list->pos + 1;
  new_elem->prev = list;
  new_elem->next = NULL;
  list->next = new_elem;
  return (new_elem);
}

void		print_list(t_hist *list)
{
  while (list->prev != NULL)
    list = list->prev;
  while (list != NULL)
    {
      my_putstr("-> ", 1);
      my_putstr(list->str, 1);
      my_putstr("\n", 1);
      list = list->next;
    }
}
