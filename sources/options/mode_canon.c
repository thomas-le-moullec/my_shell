/*
** mode_canon.c for canon in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh/sources/options
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 16:44:55 2016 Hervé TCHIKLADZE
** Last update Tue May 17 17:37:43 2016 Hervé TCHIKLADZE
*/

#include "42sh.h"

int			mode_canon(int mode)
{
  static struct termios	prev;
  static struct termios	next;

  if (mode == 0)
    {
      if (ioctl(0, TCGETS, &prev) < 0)
	return (ERROR);
      if (ioctl(0, TCGETS, &next) < 0)
	return (ERROR);
      next.c_lflag &= ~ECHO;
      next.c_cc[VTIME] = 2;
      next.c_cc[VMIN] = 0;
      if (ioctl(0, TCSETS, &next) < 0)
	return (ERROR);
    }
  else
    {
      if (ioctl(0, TCSETS, &prev) < 0)
	return (ERROR);
    }
  return (SUCCESS);
}

int		init_tab(t_data *data)
{
  tigetstr("smkx");
  data->tab_key[0].key = tigetstr("kcuu1");
  data->tab_key[0].function = fct_up;
  data->tab_key[1].key = tigetstr("kcud1");
  data->tab_key[1].function = fct_down;
  data->tab_key[2].key = tigetstr("kcuf1");
  data->tab_key[2].function = fct_right;
  data->tab_key[3].key = tigetstr("kcub1");
  data->tab_key[3].function = fct_left;
  data->tab_key[4].key = NULL;
  data->tab_key[4].function = NULL;
  return (SUCCESS);
}

int		init_term(t_data *data)
{
  int		err;

  setupterm(NULL, 1, &err);
  if (err == OK)
    {
      mode_canon(0);
      init_tab(data);
      return (SUCCESS);
    }
  return (ERROR);
}
