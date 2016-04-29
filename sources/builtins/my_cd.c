/*
** my_cd.c for my_cd in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 18:20:10 2016 Thomas CHABOT
** Last update Wed Apr 27 20:06:48 2016 Thomas CHABOT
*/

#include "42sh.h"

char		*check_cd(t_data *data)
{
  if (count_tab(data->parser.tab_args) == 1)
    return (data->shell.home);
  if (data->parser.tab_args[1][0] == '-' \
      && data->parser.tab_args[1][1] == '\0')
    return (data->shell.oldpwd);
  return (data->parser.tab_args[1]);
}

int		my_cd(t_data *data)
{
  char		*tmp;

  tmp = NULL;
  tmp = check_cd(data);
  printf("tmp = %s\n", tmp);
  if (tmp != NULL)
    {
      printf("1) data->shell.pwd = %s\n", data->shell.pwd);
      data->shell.oldpwd = my_strcpy(data->shell.pwd);
      printf("2) data->shell.pwd = %s\n", data->shell.pwd);
      if (chdir(tmp) == ERROR)
	return (ERROR);
      get_pwd(data);
      printf("3) data->shell.pwd = %s\n", data->shell.pwd);
      return (SUCCESS);
    }
  return (ERROR);
}
