/*
** alias.c for alias in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Wed May 18 16:23:34 2016 Thomas CHABOT
** Last update Mon May 23 17:47:50 2016 Hervé TCHIKLADZE
*/

#include "42sh.h"

t_alias          *add_elem_alias(t_alias *alias, char *cmd, char *name)
{
  t_alias        *new_elem;

  new_elem = NULL;
  new_elem = my_mallok(new_elem, sizeof(*new_elem));
  new_elem->cmd = my_strcpy(cmd);
  new_elem->name = my_strcpy(name);
  if (alias == NULL)
    {
      new_elem->prev = NULL;
      new_elem->next = NULL;
      return (new_elem);
    }
  new_elem->prev = alias;
  new_elem->next = NULL;
  alias->next = new_elem;
  return (new_elem);
}

int		check_valid_alias(char *str)
{
  int		j;
  int		ret;

  j = 0;
  while (str[j] != '\0' && str[j] != '=')
    j++;
  if (str[j] == '\0')
    return (ERROR);
  ret = j;
  j++;
  while (str[j] != '\0')
    {
      if (str[j] == '=')
	return (ERROR);
      j++;
    }
  return (ret);
}

int		pars_alias(char *str, t_data *data, char *cmd, char *name)
{
  int		i;
  int		j;

  i = 0;
  str = &str[5];
  if ((j = check_valid_alias(str)) == ERROR)
    return (ERROR);
  name = my_mallok(name, sizeof(char) * (j + 1));
  cmd = my_mallok(cmd, sizeof(char) * (my_strlen(str) - j + 1));
  j = 1;
  while (str[j] != '=')
    name[i++] = str[j++];
  name[i] = '\0';
  i = 0;
  j++;
  while (str[j] != '\0')
    cmd[i++] = str[j++];
  cmd[i] = '\0';
  cmd = cut_extrem(cmd);
  data->alias = add_elem_alias(data->alias, cmd, name);
  return (SUCCESS);
}

int		init_list_alias(t_data *data)
{
  char		*tmp;
  char		**tabo;
  int		fd;
  int		j;
  int		size;

  tmp = NULL;
  if ((fd = open(my_strcat(data->shell.home,"/.bashrc", 0), O_RDONLY)) == ERROR)
    return (ERROR);
  size = count_size_line_file(fd, 0);
  close(fd);
  if ((fd = open(my_strcat(data->shell.home,"/.bashrc", 0), O_RDONLY)) == ERROR)
    return (ERROR);
  tmp = my_mallok(tmp, sizeof(char) * (size + 1));
  if ((j = read(fd, tmp, size)) < 0)
    return (ERROR);
  tmp[j] = '\0';
  j = 0;
  tabo = my_str_to_wordtab(tmp, "\n");
  while (tabo[j] != NULL)
    {
      if (my_strncmp(tabo[j], "alias ", 5) == SUCCESS)
	pars_alias(tabo[j], data, NULL, NULL);
      j++;
    }
  close(fd);
  return (SUCCESS);
}
