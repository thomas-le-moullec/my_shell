/*
** take_redir.c for take_redir in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 15:19:24 2016 Thomas CHABOT
** Last update Sat May 28 14:27:44 2016 leo LE DIOURON
*/

#include "42sh.h"

int		manage_outfile(t_data *data, int i, int *j)
{
  if (take_outfile(data->parser.tab_cond[i], *j, data) == ERROR)
    return (ERROR);
  if ((data->parser.tab_cond[i] = \
       epur_redir(data->parser.tab_cond[i], *j)) == NULL)
    return (ERROR);
  *j = 0;
  return (SUCCESS);
}

int		manage_infile(t_data *data, int i, int *j)
{
  if (take_infile(data->parser.tab_cond[i], *j, data) == ERROR)
    return (ERROR);
  if ((data->parser.tab_cond[i] = \
       epur_redir(data->parser.tab_cond[i], *j)) == NULL)
    return (ERROR);
  *j = 0;
  return (SUCCESS);
}

int		check_invalid_null(t_data *data, int i)
{
  char		**tabo;
  int		ret;

  tabo = my_str_to_wordtab(data->parser.tab_cond[i], " ");
  ret = count_tab(tabo);
  if (ret == 1)
    {
      if (tabo[0][0] == '>' || tabo[0][0] == '<')
	return (ERROR);
    }
  if (ret == 2)
    {
      if (my_strcmp(">" , tabo[0]) == SUCCESS ||
	  my_strcmp("<" , tabo[0]) == SUCCESS ||
	  my_strcmp(">>" , tabo[0]) == SUCCESS ||
	  my_strcmp("<<" , tabo[0]) == SUCCESS)
	return (ERROR);
    }
  return (SUCCESS);
}

int		parser_redir(t_data *data, int i)
{
  int		j;

  j = 0;
  if (check_redir_in(data, data->parser.tab_cond[i]) == ERROR \
      || check_redir_out(data, data->parser.tab_cond[i]) == ERROR)
    return (STOP);
  while (data->parser.tab_cond[i][j] != '\0')
    {
      if (check_invalid_null(data, i) == ERROR)
	return (my_put_error("Invalid null command.\n", 1));
      if (data->parser.tab_cond[i][j] == '>')
	if (manage_outfile(data, i, &j) == ERROR)
	  return (STOP);
      if (data->parser.tab_cond[i][j] == '<')
	if (manage_infile(data, i, &j) == ERROR)
	  return (STOP);
      j++;
    }
  return (SUCCESS);
}
