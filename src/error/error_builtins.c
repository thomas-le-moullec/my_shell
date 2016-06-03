/*
** error_builtins.c for error_builtins in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Mon May 16 14:34:21 2016 Thomas CHABOT
** Last update Thu Jun  2 19:19:35 2016 Thomas CHABOT
*/

#include "42sh.h"

int		not_found_cmd(t_data *data)
{
  int		i;

  i = 1;
  while (data->parser.tab_args[i])
    {
      my_putstr(data->parser.tab_args[i], 1);
      my_putchar(' ', 1);
      i++;
    }
  my_putstr(NOT_FOUND, 1);
  data->shell.exit_status = 1;
  return (ERROR);
}

int		error_denied(t_data *data, char *str)
{
  my_putstr(str, 1);
  my_putstr(PERM_DENIED, 1);
  data->shell.exit_status = 1;
  return (ERROR);
}

void		error_no_file(t_data *data, char *str)
{
  my_putstr(str, 1);
  my_putstr(FOUND_DIR, 1);
  data->shell.exit_status = 1;
}

int		error_alpha(t_data *data, int flag)
{
  if (flag == 1)
    my_putstr(SET_LETTER, 1);
  if (flag == 2)
    my_putstr(SET_ALPHA, 1);
  data->shell.exit_status = 1;
  return (ERROR);
}

int		error_event(t_data *data, char *str)
{
  my_putstr(str, 1);
  my_putstr(EVENT, 1);
  data->shell.exit_status = 1;
  while (data->hist->next != NULL)
    data->hist = data->hist->next;
  return (ERROR);
}
