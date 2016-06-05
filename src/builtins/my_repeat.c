/*
** my_repeat.c for my_repeat in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Thu Jun  2 10:37:07 2016 Thomas CHABOT
** Last update Sun Jun  5 16:17:30 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static char		**my_repeat_change(char **tabo)
{
  int			i;
  int			j;
  int			a;
  char			**new_tabo;

  i = 1;
  j = 0;
  a = 0;
  new_tabo = NULL;
  new_tabo = my_mallok(new_tabo, sizeof(*new_tabo) * count_tab(tabo));
  while (tabo[++i])
    {
      a = 0;
      new_tabo[j] = NULL;
      new_tabo[j] = my_mallok(new_tabo[j], sizeof(*new_tabo[j]) \
			      * (my_strlen(tabo[i]) + 1));
      while (tabo[i][a])
	{
	  new_tabo[j][a] = tabo[i][a];
	  a++;
	}
      new_tabo[j++][a] = '\0';
    }
  new_tabo[j] = '\0';
  return (new_tabo);
}

int		my_repeat(t_data *data)
{
  int		i;

  i = 0;
  if (my_strcmp(data->parser.tab_args[0], "repeat") != SUCCESS)
    return (STOP);
  i = count_tab(data->parser.tab_args);
  if (i < 3)
    return (my_put_error(REPEAT_FEW, 1));
  if ((data->shell.nb_repeat = my_getnbr_repeat \
       (data->parser.tab_args[1])) == ERROR_REPEAT)
    return (my_put_error(BAD_FORM, 1));
  data->shell.nb_repeat -= 1;
  data->parser.tab_args = my_repeat_change(data->parser.tab_args);
  return (SUCCESS);
}
