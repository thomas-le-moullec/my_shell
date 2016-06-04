/*
** get_env.c for  in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 12:42:17 2016 Thomas CHABOT
** Last update Sat Jun  4 20:51:08 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

int		get_env(t_data *data, char **ae)
{
  int		i;
  int		j;

  i = 0;
  if (ae == NULL)
    return (STOP);
  data->shell.env = my_mallok(data->shell.env, \
			      (count_tab(ae) + 1) * sizeof(*data->shell.env));
  while (ae[i] != NULL)
    {
      j = 0;
      data->shell.env[i] = NULL;
      data->shell.env[i] = my_mallok \
	(data->shell.env[i], sizeof(*data->shell.env[i]) * \
	 (my_strlen(ae[i]) + 1));
      while (ae[i][j] != '\0')
	{
	  data->shell.env[i][j] = ae[i][j];
	  j++;
	}
      data->shell.env[i][j] = '\0';
      i++;
    }
  data->shell.env[i] = NULL;
  return (SUCCESS);
}
