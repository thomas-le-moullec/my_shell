/*
** signal.c for signal in /home/payrau_a/rendu/aProjets/PSU/PSU_2015_42sh/src
** 
** Made by steeve payraudeau
** Login   <payrau_a@epitech.net>
** 
** Started on  Tue May 24 13:24:43 2016 steeve payraudeau
** Last update Sat Jun  4 17:15:55 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

void		my_stop(char *str, int nbr)
{
  if (isatty(0) != 0)
    mode_canon(1);
  my_putstr(str, 1);
  exit(nbr);
}

void		*my_handler(int sign)
{
  if (sign == SIGINT)
    {
      my_putstr("\n/$> ", 1);
      return (NULL);
    }
  if (sign == SIGSEGV)
    my_stop(SIG_SIGSEGV, 139);
  if (sign == SIGUSR1)
    my_stop(SIG_USR1, 138);
  if (sign == SIGUSR2)
    my_stop(SIG_USR2, 140);
  return (NULL);
}

void		init_signaux()
{
  if ((signal(SIGINT, (void (*)(int))my_handler)) == SIG_ERR)
    my_putstr(ERR_SIGINT, 2);
  if ((signal(SIGTERM, (void (*)(int))my_handler)) == SIG_ERR)
    my_putstr(ERR_SIGTERM, 2);
  if ((signal(SIGSEGV, (void (*)(int))my_handler)) == SIG_ERR)
    my_putstr(ERR_SIGSEGV, 2);
  if ((signal(SIGQUIT, (void (*)(int))my_handler)) == SIG_ERR)
    my_putstr(ERR_SIGQUIT, 2);
  if ((signal(SIGUSR1, (void (*)(int))my_handler)) == SIG_ERR)
    my_putstr(ERR_SIGUSR1, 2);
  if ((signal(SIGUSR2, (void (*)(int))my_handler)) == SIG_ERR)
    my_putstr(ERR_SIGUSR2, 2);
  if ((signal(SIGTSTP, (void (*)(int))my_handler)) == SIG_ERR)
    my_putstr(ERR_SIGTSTP, 2);
}
