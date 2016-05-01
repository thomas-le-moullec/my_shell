/*
** check_redir.c for check_redir.c in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 15:16:32 2016 leo LE DIOURON
** Last update Sun May  1 16:21:22 2016 leo LE DIOURON
*/

#include "42sh.h"

int             check_redir_in(char *str)
{
  int           i;
  int           nb_in;

  i = 0;
  nb_in = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '<')
        {
          nb_in++;
          i++;
        }
      if (str[i] == '<')
        i++;
      if (str[i] != '\0')
        i++;
    }
  if (nb_in > 1)
    return (ambiguous(0));
  return (SUCCESS);
}

int             check_redir_out(char *str)
{
  int           i;
  int           nb_out;

  i = 0;
  nb_out = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '>')
        {
          nb_out++;
          i++;
        }
      if (str[i] == '>')
	i++;
      if (str[i] != '\0')
        i++;
    }
  if (nb_out > 1)
    return (ambiguous(1));
  return (SUCCESS);
}
