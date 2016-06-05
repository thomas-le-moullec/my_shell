/*
** which_where_tools.c for wich_where_tools in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Sun Jun  5 13:59:19 2016 Thomas CHABOT
** Last update Sun Jun  5 14:25:07 2016 Thomas CHABOT
*/

#include "42sh.h"

int                     show_the_alias(t_data *data, char *str)
{
  my_putstr(cut_str(str), 1);
  my_putstr(":\taliased to ", 1);
  my_putstr(data->alias->cmd, 1);
  my_putchar('\n', 1);
  return (1);
}

int                     is_in_alias(t_data *data, char *str)
{
  while (data->alias->prev != NULL)
    data->alias = data->alias->prev;
  while (data->alias->next != NULL)
    {
      if (my_strcmp(data->alias->name, str) == SUCCESS)
        return (show_the_alias(data, str));
      data->alias = data->alias->next;
    }
  if (my_strcmp(data->alias->name, cut_str(str)) == SUCCESS)
    return (show_the_alias(data, str));
  return (SUCCESS);
}

int                     show_the_built(char *str, int flag)
{
  my_putstr(str, 1);
  if (flag == 1)
    my_putstr(BUILT_WHI, 1);
  else
    my_putstr(BUILT_WHE, 1);
  return (1);
}

char			*cut_str(char *str)
{
  char			*new_str;
  int			i;
  int			j;

  new_str = NULL;
  i = my_strlen(str);
  new_str = my_mallok(new_str, sizeof(*new_str) * my_strlen(str));
  while (i > 0 && str[i] != '/')
    i--;
  i++;
  j = 0;
  while (str[i])
    new_str[j++] = str[i++];
  new_str[j] = '\0';
  return (new_str);
}

int			is_builtin(t_data *data, char *str)
{
  int			i;

  i = 0;
  while (i < 15)
    {
      if (my_strcmp(data->shell.tab_builtins[i], str) == SUCCESS)
        return (2);
      i++;
    }
  return (SUCCESS);
}
