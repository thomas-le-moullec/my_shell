/*
** signal.c for signal in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue May 24 13:51:52 2016 Thomas CHABOT
** Last update Wed Jun  1 17:06:46 2016 leo LE DIOURON
*/

#include "42sh.h"

int			check_signal(t_data *data, int status)
{
  int			i;
  static t_signal	signal[] = {
    {SIGABRT, SIG_SIGABRT},
    {SIGFPE, SIG_SIGFPE},
    {SIGQUIT, SIG_SIGQUIT},
    {SIGSEGV, SIG_SIGSEGV},
    {SIGILL, SIG_SIGILL},
  };

  i = 0;
  while (i < NB_SIGNALS)
    {
      if (status == signal[i].status)
	{
	  data->shell.exit_status = status + 128;
	  my_putstr(signal[i].msg, 1);
	}
      i++;
    }
  return (SUCCESS);
}
