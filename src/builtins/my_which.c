/*
** my_which.c for my_which in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Thu Jun  2 13:38:52 2016 Thomas CHABOT
** Last update Fri Jun  3 10:36:00 2016 Thomas CHABOT
*/

#include "42sh.h"

int		check_which(char *tmp, int limit)
{
  if (access(tmp, X_OK) == SUCCESS)
    {
      my_putstr(get_which(tmp), 1);
      my_putchar('\n', 1);
      limit = 1;
    }
  return (limit);
}

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
  static int	b = 0;

  a = 1;
  while (nb-- > 1 && limit == 0)
    {
      i = 0;
      b = 0;
      while (data->shell.path[i] && limit == 0)
	{
	  tmp = NULL;
	  tmp = my_strcat(data->shell.path[i], data->parser.tab_args[a], '/');
	  if (is_builtin(data, data->parser.tab_args[a]) == 2 && b == 0)
	    {
	      my_putstr(data->parser.tab_args[a], 1);
	      my_putstr(": shell built-in command.\n", 1);
	      b = 1;
	      limit = 1;
	    }
	  limit = check_which(tmp, limit);
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
