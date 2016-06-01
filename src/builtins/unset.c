/*
** unset.c for unset in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Wed Jun  1 21:20:02 2016 leo LE DIOURON
** Last update Wed Jun  1 21:35:08 2016 leo LE DIOURON
*/

#include "42sh.h"

int             delete_local(t_data *data)
{
  if (data->local->next != NULL && data->local->prev != NULL)
    {
      data->local->next->prev = data->local->prev;
      data->local->prev->next = data->local->next;
      data->local = data->local->prev;
      return (SUCCESS);
    }
  if (data->local->prev == NULL && data->local->next == NULL)
    {
      data->local = NULL;
      return (SUCCESS);
    }
  if (data->local->next == NULL)
    {
      data->local->prev->next = NULL;
      data->local = data->local->prev;
      return (SUCCESS);
    }
  if (data->local->prev == NULL)
    {
      data->local->next->prev = NULL;
      data->local = data->local->next;
      return (SUCCESS);
    }
  return (SUCCESS);
}

int		my_unset(t_data *data)
{
  delete_local(data);
  return (SUCCESS);
}
