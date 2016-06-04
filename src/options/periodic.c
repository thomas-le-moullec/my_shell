/*
** periodic.c for periodic in /home/le-mou_t/rendu/PSU_2015_42sh
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Fri Jun  3 15:00:02 2016 Thomas LE MOULLEC
** Last update Sat Jun  4 19:59:22 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

int			get_time_period()
{
  struct tm		*tmp;
  time_t		t;
  int			sec;

  sec = 0;
  if (!(t = time(NULL)))
    return (ERROR);
  if (!(tmp = gmtime(&t)))
    return (ERROR);
  sec = t;
  return (sec);
}

int			periodic(t_data *data)
{
  char			*tmp;
  char			*line_tmp;
  char			*str_time;

  if ((tmp = check_in_alias(data, "periodic")) != NULL && \
      ((str_time = check_in_set(data, "tperiod")) != NULL) && \
      (data->period.cycle = my_getnbr(str_time)) != ERROR)
    {
      if ((data->period.cmpt = get_time_period()) == 0)
	return (ERROR);
      if (data->period.cmpt - data->period.init >= data->period.cycle)
	{
	  data->period.init = data->period.cmpt;
	  line_tmp = my_strcpy(data->shell.line);
	  data->shell.line = my_strcpy(tmp);
	  parser_line(data);
	  data->shell.line = my_strcpy(line_tmp);
	}
    }
  return (SUCCESS);
}
