/*
** my_free.c for my_free in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 10:35:36 2016 Thomas CHABOT
** Last update Tue May 17 17:46:30 2016 Hervé TCHIKLADZE
*/

#include "42sh.h"

void		my_free_cond(t_data *data)
{
  data->parser.infile = my_free(data->parser.infile);
  data->parser.outfile = my_free(data->parser.outfile);
  data->parser.tab_pipe = my_free_tab(data->parser.tab_pipe);
  data->parser.nb_pipe = my_free(data->parser.nb_pipe);
}

void		*my_free_tab(char **tabo)
{
  int		i;

  i = 0;
  if (tabo != NULL)
    {
      while (tabo[i] != NULL)
	{
	  my_free(tabo[i]);
	  i++;
	}
      my_free(tabo);
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
