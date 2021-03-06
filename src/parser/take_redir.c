/*
** take_redir.c for take_redir in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 15:15:06 2016 leo LE DIOURON
** Last update Sat Jun  4 20:46:10 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

int             take_outfile(char *str, int i, t_data *data)
{
  int           j;

  data->parser.db_out = 0;
  if (str[i + 1] == '>')
    {
      data->parser.db_out = 1;
      i++;
    }
  i++;
  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t') && str[i] != '<')
    i++;
  if (str[i] == '<' || str[i] == '\0' || str[i] == '>')
    return (my_put_error(MISSING_NAME, 1));
  j = i;
  while (str[j] != '\0' && str[j] != ' ' && str[j] != '\t')
    j++;
  data->parser.outfile = my_mallok \
    (data->parser.outfile, sizeof(*data->parser.outfile) * (j - i + 1));
  j = 0;
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && \
	 str[i] != '<' && str[i] != '>')
    data->parser.outfile[j++] = str[i++];
  data->parser.outfile[j] = '\0';
  return (SUCCESS);
}

int             take_infile(char *str, int i, t_data *data)
{
  int           j;

  data->parser.db_in = 0;
  if (str[i + 1] == '<')
    {
      data->parser.db_in = 1;
      i++;
    }
  i++;
  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t') && str[i] != '>')
    i++;
  if (str[i] == '>' || str[i] == '\0' || str[i] == '<')
    return (my_put_error(MISSING_NAME, 1));
  j = i;
  while (str[j] != '\0' && str[j] != ' ' && str[j] != '\t')
    j++;
  data->parser.infile = my_mallok \
    (data->parser.infile, sizeof(*data->parser.infile) * (j - i + 1));
  j = 0;
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && \
	 str[i] != '<' && str[i] != '>')
    data->parser.infile[j++] = str[i++];
  data->parser.infile[j] = '\0';
  return (SUCCESS);
}
