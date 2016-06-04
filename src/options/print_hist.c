/*
** print_hist.c for print_hist in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue May 31 13:45:29 2016 Thomas CHABOT
** Last update Sat Jun  4 20:02:53 2016 Thomas LE MOULLEC
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

static void		print_hist_date(t_data *data)
{
  my_put_nbr(data->hist->hour + 2, 1);
  my_putchar(':', 1);
  my_put_nbr(data->hist->min, 1);
  my_putstr("  ", 1);
}

static int	disp_hist(t_data *data, int nb_line)
{
  my_put_nbr(nb_line++, 1);
  my_putstr("  ", 1);
  print_hist_date(data);
  my_putstr(data->hist->str, 1);
  my_putstr("\n", 1);
  return (nb_line);
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
      nb_line = disp_hist(data, nb_line);
      data->hist = data->hist->next;
    }
  nb_line = disp_hist(data, nb_line);
  return (SUCCESS);
}
