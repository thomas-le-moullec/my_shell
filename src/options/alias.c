/*
** alias.c for alias in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Wed May 18 16:23:34 2016 Thomas CHABOT
** Last update Wed Jun  1 21:10:18 2016 leo LE DIOURON
*/

#include "42sh.h"

t_alias		*add_elem_alias(t_alias *alias, char *cmd, char *name)
{
  t_alias	*new_elem;

  new_elem = NULL;
  new_elem = my_mallok(new_elem, sizeof(*new_elem));
  new_elem->cmd = my_strcpy(cmd);
  new_elem->name = my_strcpy(name);
  if (alias == NULL)
    {
      new_elem->prev = NULL;
      new_elem->next = NULL;
      return (new_elem);
    }
  new_elem->prev = alias;
  new_elem->next = NULL;
  alias->next = new_elem;
  return (new_elem);
}
