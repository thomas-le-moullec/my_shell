/*
** mode_canon.c for canon in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh/sources/options
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 16:44:55 2016 Hervé TCHIKLADZE
** Last update Sat Jun  4 20:10:53 2016 Thomas LE MOULLEC
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
      next.c_cc[VMIN] = 1;
      next.c_cc[VTIME] = 0;
      if (ioctl(0, TCSETS, &next) < 0)
	return (ERROR);
    }
  else
    if (ioctl(0, TCSETS, &prev) < 0)
      return (ERROR);
  return (SUCCESS);
}

static int		init_tab_ctrl(t_data *data)
{
  data->tab_key[9].key = my_char(LCTRL);
  data->tab_key[9].function = fct_clear;
  data->tab_key[10].key = my_char(DCTRL);
  data->tab_key[10].function = fct_eof;
  data->tab_key[11].key = my_char(ACTRL);
  data->tab_key[11].function = fct_kome;
  data->tab_key[12].key = my_char(ECTRL);
  data->tab_key[12].function = fct_end;
  data->tab_key[13].key = my_char(UCTRL);
  data->tab_key[13].function = fct_reset;
  data->tab_key[14].key = NULL;
  data->tab_key[14].function = NULL;
  return (SUCCESS);
}

static void		init_fct_key(t_data *data)
{
  data->tab_key[0].function = fct_up;
  data->tab_key[1].function = fct_down;
  data->tab_key[2].function = fct_right;
  data->tab_key[3].function = fct_left;
  data->tab_key[4].function = fct_tab;
  data->tab_key[5].function = fct_delete;
  data->tab_key[6].function = fct_supp;
  data->tab_key[7].function = fct_kome;
  data->tab_key[8].function = fct_end;
}

static int		init_tab(t_data *data)
{
  char			*tmp;

  tmp = NULL;
  if ((tmp = tigetstr("smkx")) == NULL)
    exit(0);
  my_putstr(tmp, 1);
  if ((data->tab_key[0].key = tigetstr("kcuu1")) == NULL ||
      (data->tab_key[1].key = tigetstr("kcud1")) == NULL ||
      (data->tab_key[2].key = tigetstr("kcuf1")) == NULL ||
      (data->tab_key[3].key = tigetstr("kcub1")) == NULL ||
      (data->tab_key[4].key = tigetstr("ht")) == NULL ||
      (data->tab_key[5].key = tigetstr("kbs")) == NULL ||
      (data->tab_key[6].key = tigetstr("kdch1")) == NULL ||
      (data->tab_key[7].key = tigetstr("khome")) == NULL ||
      (data->tab_key[8].key = tigetstr("kend")) == NULL)
    exit(0);
  init_fct_key(data);
  init_tab_ctrl(data);
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
  return (ERROR);
}
