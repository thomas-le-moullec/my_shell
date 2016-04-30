/*
** get_next_line.c for get_next_line in /home/le-dio_l/Modules/Module_Prog_shell/Minishell2/PSU_2015_minishell2
**
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
**
** Started on  Tue Mar 29 12:39:25 2016 leo LE DIOURON
** Last update Sat Apr 30 11:56:30 2016 leo LE DIOURON
*/

#include "42sh.h"

char		*mallc_line(char *line)
{
  int		end;

  line = my_mallok(line, 1000);
  if ((end = read(0, line, 1000)) <= 0)
    return (NULL);
  line[end - 1] = '\0';
  return (line);
}

char            *get_next_line()
{
  static char   *line;
  static int    i = 0;
  char          *line_inter;
  int		j;

  j = 0;
  line_inter = NULL;
  line_inter = my_mallok(line_inter, 1000);
  line_inter[0] = '\0';
  if (i == 0)
    if ((line = mallc_line(line)) == NULL)
      return (NULL);
  while (line[i] != '\n' && line[i] != '\0')
    line_inter[j++] = line[i++];
  line_inter[j] = '\0';
  if (line[i] == '\n')
    i++;
  else
    {
      i = 0;
      my_free(line);
    }
  return (line_inter);
}
