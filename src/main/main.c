/*
** main.c for main in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Tue Apr 26 09:08:44 2016 Thomas CHABOT
** Last update Fri Jun  3 10:51:01 2016 steeve payraudeau
*/

#include "42sh.h"

void		end_fct(t_data *data)
{
  my_free_tab(data->shell.env);
  my_free(data->shell.pwd);
  my_free(data->shell.cond);
  my_free(data->shell.oldpwd);
  my_free_alias(data->alias);
  data->shell.path = my_free_tab(data->shell.path);
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
    {
      my_shell_key(&data);
    }
  else
    my_shell(&data);
  end_fct(&data);
  return (data.shell.exit_status);
}
