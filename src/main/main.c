/*
** main.c for main in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Tue Apr 26 09:08:44 2016 Thomas CHABOT
** Last update Tue May 31 20:14:20 2016 steeve payraudeau
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
  if (isatty(0) == 0)
    my_shell(&data);
  else
    my_shell_key(&data);
  end_fct(&data);
  return (data.shell.exit_status);
}
