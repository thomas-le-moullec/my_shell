/*
** take_redir.c for take_redir in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 15:19:24 2016 Thomas CHABOT
** Last update Tue Apr 26 16:19:41 2016 Thomas CHABOT
*/

#include "42sh.h"

int		check_redir_in(char *str)
{
  int		i;
  int		nb_in;

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
    return (ERROR);
  return (SUCCESS);
}

int		check_redir_out(char *str)
{
  int		i;
  int		nb_out;

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
    return (ERROR);
  return (SUCCESS);
}

int		take_outfile(char *str, int i)
{
  int		j;

  if (str[i + 1] == '>')
    {
      data->parser.db_out = 1;
      i++;
    }
  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
    i++;
  j = i;
  while (str[j] != '\0' && str[j] != ' ' && str[j] != '\t' && str[j] != '<')
    j++;
  if (str[j] == '<')
    return (ERROR);
  data->parser.oufile = my_mallok(data->parser.outfile, (j - i + 1));
  j = 0;
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
    data->parser.outfile[j++] = str[i++];
  data->parser.outfile[j] = '\0';
  return (SUCCESS);
}

int		take_infile(char *str, int i)
{
  int		j;

  if (str[i + 1] == '<')
    {
      data->parser.db_in = 1;
      i++;
    }
  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
    i++;
  j = i;
  while (str[j] != '\0' && str[j] != ' ' && str[j] != '\t' && str[j] != '<')
    j++;
  if (str[j] == '>')
    return (ERROR);
  data->parser.infile = my_mallok(data->parser.infile, (j - i + 1));
  j = 0;
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
    data->parser.infile[j++] = str[i++];
  data->parser.infile[j] = '\0';
  return (SUCCESS);
}

int		take_redir(t_data *data, int i)
{
  int		j;

  j = 0;
  if (check_redir_in(data->parser.tab_cond[i]) != ERROR \
      || check_redir_out(data->parser.tab_cond[i]) != ERROR)
    return (ERROR);
  while (data->parser.tab_cond[i][j] != '\0')
    {
      if (data->parser.tab_cond[i][j] == '>')
	if (take_outfile(data->parser.tab_cond[i], j) == ERROR)
	  return (ERROR);
      if (data->parser.tab_cond[i][j] == '<')
	if (take_infile(data->parser.tab_cond[i], j) == ERROR)
	  return (ERROR);
      j++;
    }
  return (SUCCESS);
}
