/*
** fct_eod.c for eod in /home/payrau_a/rendu/aProjets/PSU/PSU_2015_42sh/src/options/line_edition
** 
** Made by steeve payraudeau
** Login   <payrau_a@epitech.net>
** 
** Started on  Wed Jun  1 21:49:45 2016 steeve payraudeau
** Last update Fri Jun  3 13:37:20 2016 steeve payraudeau
*/

#include "42sh.h"

int             fct_eof(t_data *data, int *i)
{
  (void)i;
  if (check_in_set(data, "ignoreeof") != NULL)
    {
      my_putstr("^D\n", 1);
      my_putstr(IEOF, 1);
      disp_prompt(data);
      if (data->shell.line != NULL)
	my_putstr(data->shell.line, 1);
      return (SUCCESS);
    }
  return (ERROR);
}
