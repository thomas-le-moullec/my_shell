/*
** print_hist.c for print_hist in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue May 31 13:45:29 2016 Thomas CHABOT
** Last update Tue May 31 13:46:17 2016 Thomas CHABOT
*/

#include "42sh.h"

int             print_hist(t_data *data)
{
  int           nb_line;

  nb_line = 0;
  if (data->hist == NULL)
    return (ERROR);
  while (data->hist->prev != NULL)
    data->hist = data->hist->prev;
  while (data->hist->next != NULL)
    {
      my_put_nbr(nb_line++, 1);
      my_putstr("  ", 1);
      my_putstr(data->hist->str, 1);
      my_putstr("\n", 1);
      data->hist = data->hist->next;
    }
  my_put_nbr(nb_line++, 1);
  my_putstr("  ", 1);
  my_putstr(data->hist->str, 1);
  my_putstr("\n", 1);
  return (SUCCESS);
}
