/*
** get_next_line.c for get_next_line in /home/le-dio_l/Modules/Module_Prog_shell/Minishell2/PSU_2015_minishell2
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Tue Mar 29 12:39:25 2016 leo LE DIOURON
** Last update Sun Apr 10 14:17:29 2016 leo LE DIOURON
*/

#include "shell.h"

char		*mallc_line(char *line)
{
  int		end;

  if ((line = malloc(sizeof(char) * 1000)) == NULL)
    return (NULL);
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
  if ((line_inter = malloc(sizeof(char) * 1000)) == NULL)
    return (NULL);
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
    i = 0;
  return (line_inter);
}
