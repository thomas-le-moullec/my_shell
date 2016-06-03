/*
** set.c for set in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Wed Jun  1 21:10:27 2016 leo LE DIOURON
** Last update Thu Jun  2 10:09:05 2016 leo LE DIOURON
*/

#include "42sh.h"

void		show_set(t_data *data)
{
  while (data->local->prev != NULL)
    data->local = data->local->prev;
  while (data->local->next != NULL)
    {
      my_putstr(data->local->name, 1);
      my_putstr("\t", 1);
      my_putstr("\t", 1);
      my_putstr(data->local->cmd, 1);
      my_putstr("\n", 1);
      data->local = data->local->next;
    }
  my_putstr(data->local->name, 1);
  my_putstr("\t", 1);
  my_putstr("\t", 1);
  my_putstr(data->local->cmd, 1);
  my_putstr("\n", 1);
}

t_local         *add_elem_local(t_local *local, char *cmd, char *name)
{
  t_local       *new_elem;

  new_elem = NULL;
  new_elem = my_mallok(new_elem, sizeof(*new_elem));
  new_elem->cmd = my_strcpy(cmd);
  new_elem->name = my_strcpy(name);
  if (local == NULL)
    {
      new_elem->prev = NULL;
      new_elem->next = NULL;
      return (new_elem);
    }
  new_elem->prev = local;
  new_elem->next = NULL;
  local->next = new_elem;
  return (new_elem);
}

char		*take_name_local(char *str)
{
  char		*result;
  int		i;

  i = 0;
  result = NULL;
  result = my_mallok(result, sizeof(char) * (my_strlen(str) + 1));
  while (str[i] != '\0' && str[i] != '=')
    {
      result[i] = str[i];
      i++;
    }
  result[i] = '\0';
  return (result);
}

char		*take_cmd_local(char *str)
{
  char		*result;
  int		i;
  int		j;

  i = 0;
  j = 0;
  result = NULL;
  result = my_mallok(result, sizeof(char) * (my_strlen(str) + 1));
  while (str[i] != '\0' && str[i] != '=')
    i++;
  if (str[i] != '\0')
    i++;
  while (str[i] != '\0')
    result[j++] = str[i++];
  result[j] = '\0';
  return (result);
}

int		my_set(t_data *data)
{
  int		nb;
  int		j;
  char		*name;
  char		*cmd;

  j = 1;
  nb = count_tab(data->parser.tab_args);
  if (nb == 1)
    {
      if (data->local != NULL)
	show_set(data);
      return (SUCCESS);
    }
  while (j < nb)
    {
      name = take_name_local(data->parser.tab_args[j]);
      cmd = take_cmd_local(data->parser.tab_args[j]);
      data->local = add_elem_local(data->local, cmd, name);
      j++;
    }
  return (SUCCESS);
}
