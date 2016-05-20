/*
** my_cd.c for my_cd in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 18:20:10 2016 Thomas CHABOT
** Last update Fri May 20 15:23:05 2016 leo LE DIOURON
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
  int		err;

  tmp = NULL;
  tmp = check_cd(data);
  if (tmp != NULL)
    {
      data->shell.oldpwd = my_strcpy(data->shell.pwd);
      if (chdir(tmp) == ERROR)
	{
	  err = errno;
	  if (err == 13)
	    {
	      my_putstr(tmp, 1);
	      my_putstr(": Permission denied.\n", 1);
	      data->shell.exit_status = 1;
	    }
	  else
	    {
	      my_putstr(tmp, 1);
	      my_putstr(": No such file or directory.\n", 1);
	      data->shell.exit_status = 1;
	    }
	  return (ERROR);
	}
      get_pwd(data);
      return (SUCCESS);
    }
  return (ERROR);
}
