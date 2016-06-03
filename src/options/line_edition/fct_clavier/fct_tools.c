/*
** fct_tools.c for tool in /home/payrau_a/rendu/aProjets/PSU/PSU_2015_42sh/src/options/line_edition/fct_clavier
** 
** Made by steeve payraudeau
** Login   <payrau_a@epitech.net>
** 
** Started on  Thu Jun  2 13:19:15 2016 steeve payraudeau
** Last update Thu Jun  2 17:57:59 2016 steeve payraudeau
*/

#include "42sh.h"

int             found_tabo_comp(char **tabo, char *line)
{
  int           i;

  i = 0;
  if (line == NULL)
    return (SUCCESS);
  while (tabo[i] != NULL)
    {
      if (my_strcmp(tabo[i], line) == SUCCESS)
	return (ERROR);
      i++;
    }
  return (SUCCESS);
}

int             reinit_cursor(t_data *data, int i)
{
  int           max;

  if (data->shell.line != NULL)
    max = my_strlen(data->shell.line);
  else
    return (STOP);
  while (max > i)
    {
      my_putstr(tgetstr("le", NULL), 1);
      max--;
    }
  return (SUCCESS);
}

void            found_positions(char *str, int i, int *beg, int *end)
{
  int           tmp;

  tmp = i;
  if (tmp > 0 && str[tmp - 1] != ' ' && str[tmp - 1] != '\t')
    tmp--;
  while (str[tmp] != ' ' && str[tmp] != '\t' && tmp > 0)
    tmp--;
  if ((str[tmp] == ' ' || str[tmp] == '\t') && tmp < i)
    tmp++;
  while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
    i++;
  (*beg) = tmp;
  (*end) = i;
}
