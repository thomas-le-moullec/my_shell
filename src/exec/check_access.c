/*
** check_access.c for check_access in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Sun May 29 14:48:43 2016 Thomas CHABOT
** Last update Sun May 29 14:51:50 2016 Thomas CHABOT
*/

#include "42sh.h"

int             access_path_er(t_data *data)
{
  if (data->shell.env == NULL || (my_strlen(data->parser.tab_args[0]) < 2 || \
                                  ((data->parser.tab_args[0][0] == '.' && \
                                    data->parser.tab_args[0][1] == '/') || \
                                   data->parser.tab_args[0][0] == '/')))
    return (ERROR);
  return (SUCCESS);
}

int             access_path_file(t_data *data)
{
  struct stat   s;
  char          *dir;

  dir = get_dir(data->parser.tab_args[0]);
  if ((stat(dir, &s) != ERROR) && (((s.st_mode & S_IFDIR)) \
                                   || ((s.st_mode & S_IFREG) \
                                       && !(s.st_mode & S_IXUSR))))
    return (error_perm(data));
  return (SUCCESS);
}
