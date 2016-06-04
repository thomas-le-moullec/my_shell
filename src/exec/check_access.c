/*
** check_access.c for check_access in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Sun May 29 14:48:43 2016 Thomas CHABOT
** Last update Sat Jun  4 19:29:29 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static int             access_path_er(t_data *data)
{
  if (data->shell.env == NULL || (my_strlen(data->parser.tab_args[0]) < 2 || \
                                  ((data->parser.tab_args[0][0] == '.' && \
                                    data->parser.tab_args[0][1] == '/')) ||
				  (data->parser.tab_args[0][0] == '/')))
    return (ERROR);
  return (SUCCESS);
}

static int		access_path_file(t_data *data)
{
  struct stat		s;

  if ((stat(data->parser.tab_args[0], &s) == 0) && (s.st_mode & S_IFDIR))
      return (ERROR);
  if ((stat(data->parser.tab_args[0], &s) != -1) && ((s.st_mode & S_IFREG) \
				   && !(s.st_mode & S_IXUSR) \
				   && access_path_er(data) == -1))
    return (ERROR);
  return (SUCCESS);
}

static int		find_path_exec(t_data *data)
{
  char			*tmp;
  int			i;

  i = 0;
  while (data->shell.path != NULL && data->shell.path[i] != NULL)
    {
      tmp = NULL;
      tmp = my_strcat(data->shell.path[i], data->parser.tab_args[0], '/');
      if (access(tmp, X_OK | F_OK | R_OK) == 0)
        {
          my_free(tmp);
          return (i);
        }
      tmp = my_free(tmp);
      i++;
    }
  return (ERROR);
}

int             access_path(t_data *data)
{
  char          *tmp;
  int		i;

  if (access_path_file(data) != SUCCESS)
    return (error_perm(data));
  if (access_path_er(data) == ERROR)
    return (ERROR);
  if ((i = find_path_exec(data)) != ERROR)
    return (i);
  tmp = NULL;
  tmp = my_strcat("/bin", data->parser.tab_args[0], '/');
  if (data->shell.bin == 1 && access(tmp, X_OK | F_OK | R_OK) == 0)
    {
      tmp = my_free(tmp);
      return (-2);
    }
  tmp = my_free(tmp);
  return (ERROR);
}
