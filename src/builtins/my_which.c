/*
** my_which.c for my_which in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Thu Jun  2 13:38:52 2016 Thomas CHABOT
** Last update Thu Jun  2 19:38:45 2016 Thomas CHABOT
*/

#include "42sh.h"

char		*get_which(char *str)
{
  char		*new_str;
  int		i;
  int		j;

  new_str = NULL;
  i = my_strlen(str);
  j = 0;
  while (i > 0 && str[i] != '/')
    i--;
  if (i > 0)
    i--;
  while (i > 0 && str[i] != '/')
    i--;
  new_str = my_mallok(new_str, sizeof(char) * my_strlen(str) + 1);
  while (str[i])
    new_str[j++] = str[i++];
  new_str[j] = '\0';
  return (new_str);
}

int		my_which_loop(t_data *data, char *tmp, int nb, int limit)
{
  int		a;
  int		i;

  a = 1;
  while (nb-- > 1 && limit == 0)
    {
      i = 0;
      while (data->shell.path[i] && limit == 0)
	{
	  tmp = NULL;
	  tmp = my_strcat(data->shell.path[i], data->parser.tab_args[a], '/');
	  if (access(tmp, X_OK) == SUCCESS)
	    {
	      my_putstr(get_which(tmp), 1);
	      my_putchar('\n', 1);
	      limit = 1;
	    }
	  i++;
	}
      if (nb > 1)
	limit = 0;
      a++;
    }
  return (limit);
}

int		my_which(t_data *data)
{
  int		nb;
  char          *tmp;
  int		limit;

  tmp = NULL;
  nb = count_tab(data->parser.tab_args);
  limit = 0;
  if (nb < 2)
    return (my_put_error(ERR_WHICH, 1));
  if (data->shell.path == NULL)
    return (ERROR);
  limit = my_which_loop(data, tmp, nb, limit);
  if (limit == 0)
    return (not_found_cmd(data));
  return (SUCCESS);
}
