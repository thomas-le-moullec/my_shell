/*
** init.c for init in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Tue Apr 26 12:51:48 2016 Thomas CHABOT
** Last update Tue Apr 26 18:18:09 2016 Thomas CHABOT
*/

#include "42sh.h"

int		get_home(t_data *data)
{
  int		i;

  if (i = check_env_exist(data, "HOME") != ERROR)
    data->shell.home = my_strcpy_equal(data->shell.env[i]);
  else
    data->shell.home = my_strcpy(".");
  return (SUCCESS);
}

int		get_old_pwd(t_data *data)
{
  int		i;

  if (i = check_env_exist(data, "OLDPWD") != ERROR)
    data->shell.oldpwd = my_strcpy_equal(data->shell.env[i]);
  if (i == ERROR && data->shell.pwd != NULL)
    data->shell.oldpwd = my_strcpy_equal(data->shell.pwd);
  if (i == ERROR && data->shell.pwd == NULL)
    data->shell.oldpwd = NULL;
  return (SUCCESS);
}

void		get_pwd(t_data *data)
{
  if (getcwd(data->shell.pwd, 1024) == NULL)
    data->shell.pwd = NULL;
}

void		init_shell(t_data *data)
{
  memset(&data->shell, 0, sizeof(data->shell));
  memset(&data->parser, 0, sizeof(data->shell));
  get_pwd(data);
  get_old_pwd(data);
  get_home(data);
}
