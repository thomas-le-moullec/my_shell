/*
** my_free.c for my_free in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 10:35:36 2016 Thomas CHABOT
** Last update Sun May  1 16:11:27 2016 leo LE DIOURON
*/

#include "42sh.h"

void		my_free_cond(t_data *data)
{
  data->parser.infile = my_free(data->parser.infile);
  data->parser.outfile = my_free(data->parser.outfile);
  data->parser.tab_pipe = my_free_tab(data->parser.tab_pipe);
  data->parser.nb_pipe = my_free(data->parser.nb_pipe);
}

void		*my_free_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	{
	  my_free(tab[i]);
	  i++;
	}
      my_free(tab);
    }
  return (NULL);
}

int		my_free_loop(t_data *data)
{
  if (data->shell.line[0] == '\0')
    {
      data->shell.line = my_free(data->shell.line);
      return (STOP);
    }
  data->shell.line = my_free(data->shell.line);
  data->parser.tab_sep = my_free_tab(data->parser.tab_sep);
  return (SUCCESS);
}

void		*my_free(void *ptr)
{
  if (ptr != NULL)
    free(ptr);
  return (NULL);
}
