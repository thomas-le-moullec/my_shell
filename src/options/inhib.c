/*
** inhib.c for inhib in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
**
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
**
** Started on  Tue May 17 13:07:47 2016 Hervé TCHIKLADZE
** Last update Wed Jun  1 17:26:05 2016 leo LE DIOURON
*/

#include "42sh.h"

int		args_convert(t_data *data)
{
  int		i;
  int		j;

  i = 0;
  while (data->parser.tab_args[i] != NULL)
    {
      j = 0;
      while (data->parser.tab_args[i][j] != '\0')
	{
	  if (data->parser.tab_args[i][j] < 0)
	    data->parser.tab_args[i][j] *= -1;
	  j++;
	}
      i++;
    }
  return (SUCCESS);
}

int		check_special_char(char c, char *sep)
{
  int		i;

  i = 0;
  while (sep[i] != '\0')
    {
      if (c == sep[i])
	return (SUCCESS);
      i++;
    }
  return (ERROR);
}

char		*modify_str(t_data *data, char c, int i)
{
  char		*new_string;
  int		j;

  j = -1;
  new_string = NULL;
  new_string = my_mallok(new_string, sizeof(char) * \
			 (my_strlen(data->shell.line) + 1));
  while (data->shell.line[++j] != '\0' && j < i)
    new_string[j] = data->shell.line[j];
  i++;
  while (data->shell.line[i] != '\0' && data->shell.line[i] != c)
    {
      new_string[j] = data->shell.line[i++];
      if (check_special_char(new_string[j], " \'\"\t|&;><") == SUCCESS)
	new_string[j] *= -1;
      j++;
    }
  if (data->shell.line[i] == '\0')
    return (error_quote(data, c));
  i++;
  while (data->shell.line[i] != '\0')
    new_string[j++] = data->shell.line[i++];
  new_string[j] = '\0';
  return (new_string);
}

int		inhib(t_data *data)
{
  int		i;

  i = 0;
  data->parser.quote = 0;
  while (data->shell.line[i] != '\0')
    {
      if (data->shell.line[i] == '\"' || data->shell.line[i] == '\'')
	{
	  if (data->shell.line[i] == '\"')
	    data->parser.quote = 1;
	  if (data->shell.line[i] == '\'')
	    data->parser.quote = 2;
	  if ((data->shell.line = modify_str
	       (data, data->shell.line[i], i)) == NULL)
	    return (ERROR);
	  i = -1;
	}
      i++;
    }
  return (SUCCESS);
}
