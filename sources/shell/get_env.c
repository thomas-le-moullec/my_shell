/*
** get_env.c for  in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 12:42:17 2016 Thomas CHABOT
** Last update Sat Apr 30 16:15:32 2016 leo LE DIOURON
*/

#include "42sh.h"

int		get_env(t_data *data, char **ae)
{
  int		i;
  int		j;

  i = 0;
  if (ae == NULL)
    return (STOP);
  data->shell.env = my_mallok(data->shell.env,\
			      (count_tab(ae) + 1) * sizeof(char *));
  while (ae[i] != NULL)
    {
      j = 0;
      data->shell.env[i] = NULL;
      data->shell.env[i] = my_mallok(data->shell.env[i], my_strlen(ae[i]) + 1);
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
