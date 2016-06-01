/*
** mode_canon.c for canon in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh/sources/options
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 16:44:55 2016 Hervé TCHIKLADZE
** Last update Wed Jun  1 18:09:12 2016 steeve payraudeau
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
      next.c_lflag &= ~ICANON;
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
  my_putstr(tigetstr("smkx"), 1);
  data->tab_key[0].key = tigetstr("kcuu1");
  data->tab_key[0].function = fct_up;
  data->tab_key[1].key = tigetstr("kcud1");
  data->tab_key[1].function = fct_down;
  data->tab_key[2].key = tigetstr("kcuf1");
  data->tab_key[2].function = fct_right;
  data->tab_key[3].key = tigetstr("kcub1");
  data->tab_key[3].function = fct_left;
  data->tab_key[4].key = tigetstr("ht");
  data->tab_key[4].function = fct_tab;
  data->tab_key[5].key = tigetstr("kbs");
  data->tab_key[5].function = fct_delete;
  data->tab_key[6].key = tigetstr("kdch1");
  data->tab_key[6].function = fct_supp;
  data->tab_key[7].key = tigetstr("khome");
  data->tab_key[7].function = fct_kome;
  data->tab_key[8].key = tigetstr("kend");
  data->tab_key[8].function = fct_end;
  data->tab_key[9].key = NULL;
  data->tab_key[9].function = NULL;
  return (SUCCESS);
}

int		init_term(t_data *data)
{
  int		err;

  setupterm(NULL, 1, &err);
  if (err != OK)
    {
      init_tab(data);
      return (SUCCESS);
    }
  printf("STOP\n");
  return (ERROR);
}
