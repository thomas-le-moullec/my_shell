/*
** print_autocompletion.c for print_autocompletion in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Jun  3 16:49:38 2016 leo LE DIOURON
** Last update Fri Jun  3 17:02:24 2016 leo LE DIOURON
*/

#include "42sh.h"

static int	replace_autocompletion(t_data *data, \
				       char *line, int end, int *i)
{
  while (data->shell.line[end] != '\0')
    line = strcop_char(&line, data->shell.line[end++]);
  while ((*i) > 0)
    {
      my_putstr(tgetstr("le", NULL), 1);
      my_putstr(tgetstr("dc", NULL), 1);
      (*i)--;
    }
  data->shell.line = my_strcpy(line);
  data->shell.tmp_hist = my_strcpy(data->shell.line);
  my_putstr(data->shell.line, 1);
  my_free(line);
  return (SUCCESS);
}

int             print_autocompletion(t_data *data, char *new, int *i)
{
  char          *line;
  int           beg;
  int           end;
  int           k;
  int           j;

  j = 0;
  k = 0;
  line = NULL;
  found_positions(data->shell.line, *i, &beg, &end);
  end = (*i);
  while (j < beg && data->shell.line[j] != '\0')
    line = strcop_char(&line, data->shell.line[j++]);
  while (new[k] != '\0')
    line = strcop_char(&line, new[k++]);
  if (my_strlen(new) >= 2 && new[k - 1] != '/')
    {
      line = strcop_char(&line, ' ');
      k++;
    }
  replace_autocompletion(data, line, end, i);
  (*i) = k + j;
  return (SUCCESS);
}
