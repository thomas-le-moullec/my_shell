/*
** print_hist.c for print_hist in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue May 31 13:45:29 2016 Thomas CHABOT
** Last update Tue May 31 14:54:32 2016 Thomas CHABOT
*/

#include "42sh.h"

t_hist          *get_time(t_hist *new_elem)
{
  time_t        t;
  struct tm     *tmp;

  if (!(t = time(NULL)))
    return (NULL);
  if (!(tmp = gmtime(&t)))
    return (NULL);
  new_elem->hour = (t / 3600) % 24;
  new_elem->min = (t / 60) % 60;
  return (new_elem);
}

void		print_hist_date(t_data *data)
{
  my_put_nbr(data->hist->hour + 2, 1);
  my_putchar(':', 1);
  my_put_nbr(data->hist->min, 1);
  my_putstr("  ", 1);
}

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
      print_hist_date(data);
      my_putstr(data->hist->str, 1);
      my_putstr("\n", 1);
      data->hist = data->hist->next;
    }
  my_put_nbr(nb_line++, 1);
  my_putstr("  ", 1);
  print_hist_date(data);
  my_putstr(data->hist->str, 1);
  my_putstr("\n", 1);
  return (SUCCESS);
}
