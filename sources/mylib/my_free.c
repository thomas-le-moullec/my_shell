/*
** my_free.c for my_free in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 10:35:36 2016 Thomas CHABOT
** Last update Tue Apr 26 14:40:50 2016 Thomas CHABOT
*/

#include "42sh.h"

void		my_free_tab(char **tab)
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
}

int		my_free_loop(t_data *data)
{
  if (data->shell.line[0] == '\0')
    {
      my_free(data->shell.line);
      return (STOP);
    }
  my_free(data->shell.line);
  my_free_tab(data->parser.tab_sep);
  return (SUCCESS);
}

void		my_free(void *ptr)
{
  if (ptr != NULL)
    {
      free(ptr);
      ptr = NULL;
    }
}
