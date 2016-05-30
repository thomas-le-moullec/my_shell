/*
** my_cd.c for my_cd in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 18:20:10 2016 Thomas CHABOT
** Last update Mon May 30 10:46:01 2016 Thomas CHABOT
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
  struct stat	s;

  tmp = NULL;
  tmp = check_cd(data);
  if (stat(tmp, &s) != ERROR && (s.st_mode & S_IFREG))
    return (error_dir(data, tmp));
  if (tmp != NULL)
    {
      data->shell.oldpwd = my_strcpy(data->shell.pwd);
      if (chdir(tmp) == ERROR)
	{
	  err = errno;
	  if (err == 13)
	    error_denied(data, tmp);
	  else
	    error_no_file(data, tmp);
	  return (ERROR);
	}
      get_pwd(data);
      return (SUCCESS);
    }
  return (ERROR);
}
