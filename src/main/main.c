/*
** main.c for main in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Tue Apr 26 09:08:44 2016 Thomas CHABOT
** Last update Fri Jun  3 20:48:22 2016 Thomas CHABOT
*/

#include "42sh.h"

void		end_fct(t_data *data)
{
  int		i;

  i = 9;
  my_free_alias(data->alias);
  my_free_hist(data->hist);
  my_free_shell(&data->shell);
  my_free_parser(&data->parser);
  my_free_local(data->local);
  while (data->tab_key[i].key != NULL)
    {
      data->tab_key[i].key = my_free(data->tab_key[i].key);
      i++;
    }
}

int		check_env_term(t_data *data)
{
  int		j;

  j = 0;
  while (data->shell.env != NULL && data->shell.env[j] != NULL &&
	 my_strncmp(data->shell.env[j], "TERM", 4) == ERROR)
    j++;
  if (data->shell.env[j] == NULL)
    return (ERROR);
  if (data->shell.env[j][my_strlen(data->shell.env[j]) - 1] == '=')
    return (ERROR);
  return (SUCCESS);
}

int		main(int ac, char **av, char **ae)
{
  t_data	data;

  (void)av;
  if (ac != 1)
    return (ERROR);
  memset(&data.shell, 0, sizeof(data.shell));
  memset(&data.parser, 0, sizeof(data.parser));
  get_env(&data, ae);
  init_shell(&data);
  if (isatty(0) != 0 && ae != NULL && ae[0] != NULL \
      && check_env_term(&data) == SUCCESS)
    my_shell_key(&data);
  else
    my_shell(&data);
  end_fct(&data);
  return (data.shell.exit_status);
}
