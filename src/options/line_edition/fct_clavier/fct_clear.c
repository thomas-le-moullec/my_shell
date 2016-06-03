/*
** fct_clear.c for clear in /home/payrau_a/rendu/aProjets/PSU/PSU_2015_42sh/src/options/line_edition/fct_clavier
** 
** Made by steeve payraudeau
** Login   <payrau_a@epitech.net>
** 
** Started on  Wed Jun  1 21:05:04 2016 steeve payraudeau
** Last update Wed Jun  1 22:16:09 2016 steeve payraudeau
*/

#include "42sh.h"

char		*my_char(char c)
{
  char		*new;

  new = NULL;
  new = my_mallok(new, 2 * sizeof(*new));
  new[0] = c;
  new[1] = '\0';
  return (new);
}

int             fct_clear(t_data *data, int *i)
{
  (void)i;
  my_putstr(tgetstr("cl", NULL), 1);
  disp_prompt(data);
  if (data->shell.line != NULL)
    my_putstr(data->shell.line, 1);
  return (SUCCESS);
}
