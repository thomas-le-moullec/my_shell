/*
** init.c for init in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Tue Apr 26 12:51:48 2016 Thomas CHABOT
** Last update Wed Jun  1 21:09:32 2016 leo LE DIOURON
*/

#include "42sh.h"

int		get_path(t_data *data)
{
  int		i;
  char		*tmp;

  i = 0;
  tmp = NULL;
  data->shell.bin = 0;
  data->shell.path = NULL;
  if ((i = check_env_exist(data, "PATH")) != ERROR)
    tmp = my_strcpy_equal(data->shell.env[i]);
  if (tmp != NULL && tmp[0] != '\0')
    data->shell.path = my_str_to_wordtab(tmp, ":");
  if (i == ERROR)
    data->shell.bin = 1;
  my_free(tmp);
  return (SUCCESS);
}

int		get_home(t_data *data)
{
  int		i;

  if ((i = check_env_exist(data, "HOME")) != ERROR)
    data->shell.home = my_strcpy_equal(data->shell.env[i]);
  if (i == ERROR || data->shell.home == NULL)
    data->shell.home = my_strcpy(".");
  return (SUCCESS);
}

int		get_old_pwd(t_data *data)
{
  if (data->shell.pwd != NULL)
    data->shell.oldpwd = my_strcpy_equal(data->shell.pwd);
  if (data->shell.pwd == NULL)
    data->shell.oldpwd = NULL;
  return (SUCCESS);
}

int		get_pwd(t_data *data)
{
  if ((data->shell.pwd = getcwd(data->shell.pwd, 1024)) == NULL)
    data->shell.pwd = NULL;
  return (SUCCESS);
}

int		init_shell(t_data *data)
{
  data->shell.path = NULL;
  get_pwd(data);
  get_old_pwd(data);
  get_home(data);
  init_signaux();
  data->alias = NULL;
  data->alias = add_elem_alias(data->alias, "ls -l", "ll");
  data->hist = NULL;
  data->shell.exit_status = 0;
  data->local = NULL;
  return (SUCCESS);
}
