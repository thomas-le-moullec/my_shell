/*
** signal.c for signal in /home/payrau_a/rendu/aProjets/PSU/PSU_2015_42sh/src
** 
** Made by steeve payraudeau
** Login   <payrau_a@epitech.net>
** 
** Started on  Tue May 24 13:24:43 2016 steeve payraudeau
** Last update Fri May 27 17:46:04 2016 Thomas CHABOT
*/

#include "42sh.h"

void		*my_handler(int sign)
{
  if (sign == SIGINT)
    my_putstr("\n/$> ", 1);
  return (NULL);
}

void		init_signaux()
{
  if ((signal(SIGINT, (void (*)(int))my_handler)) == SIG_ERR)
    my_putstr("ERROR SIGINT\n", 2);
  /*  if ((signal(SIGTERM, (void (*)(int))my_handler)) == SIG_ERR)
    my_putstr("ERROR SIGTERM\n", 2);
  if ((signal(SIGQUIT, (void (*)(int))my_handler)) == SIG_ERR)
    my_putstr("ERROR SIGQUIT\n", 2);
  if ((signal(SIGUSR1, (void (*)(int))my_handler)) == SIG_ERR)
    my_putstr("ERROR SIGUSR1\n", 2);
  if ((signal(SIGUSR2, (void (*)(int))my_handler)) == SIG_ERR)
    my_putstr("ERROR SIGUSR2\n", 2);
  if ((signal(SIGTSTP, (void (*)(int))my_handler)) == SIG_ERR)
    my_putstr("ERROR SIGTSTP\n", 2);
  if ((signal(SIGTSTP, (void (*)(int))my_handler)) == SIG_ERR)
  my_putstr("ERROR SIGTSTP\n", 2); */
}
