/*
** main.c for main in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Tue Apr 26 09:08:44 2016 Thomas CHABOT
** Last update Sun May  1 16:12:31 2016 leo LE DIOURON
*/

#include "42sh.h"

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
  my_shell(&data);
  my_free_tab(data.shell.env);
  my_free(data.shell.pwd);
  my_free(data.shell.oldpwd);
  return (SUCCESS);
}
