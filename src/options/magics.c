/*
** magics.c for magics in /home/le-mou_t/rendu/PSU_2015_42sh/src/options
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Tue May 31 14:37:40 2016 Thomas LE MOULLEC
** Last update Thu Jun  2 10:22:40 2016 Thomas CHABOT
*/

#include "42sh.h"

char		**my_magic_wordtab(char *str, int cmpt)
{
  char		**tabo;
  int		i;
  int		x;
  int		y;

  tabo = NULL;
  i = 0;
  y = 0;
  tabo = my_mallok(tabo, sizeof(char *) * (cmpt + 1));
  while (str[i] != '\0')
    {
      x = 0;
      if (str[i] == '`')
	{
	  i++;
	  tabo[y] = my_mallok(tabo[y], sizeof(char) * (my_strlen(str) + 1));
	  while (str[i] != '\0' && str[i] != '`')
	    tabo[y][x++] = str[i++];
	  tabo[y][x] = '\0';
	  y++;
	}
      if (str[i] != '\0')
	i++;
    }
  tabo[y] = NULL;
  return (tabo);
}

char		*epur_return_line(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	str[i] = ' ';
      i++;
    }
  return (str);
}

char		*change_magic_result(char *line, char *buffer)
{
  int           k;
  char          *result;
  int		f;
  int		j;

  j = 0;
  f = 0;
  k = 0;
  result = NULL;
  result = my_mallok(result, sizeof(char) *
                     (my_strlen(line)
                      + my_strlen(buffer) + 1));
  while (line[k] != '\0' && line[k] != '`')
    {
      result[k] = line[k];
      k++;
    }
  j = k + 1;
  while (buffer[f] != '\0')
    result[k++] = buffer[f++];
  k--;
  f = 0;
  while (line[j] != '\0' && line[j] != '`')
    j++;
  j++;
  while (line[j] != '\0')
    result[k++] = line[j++];
  result[k] = '\0';
  free(line);
  free(buffer);
  result = epur_return_line(result);
  return (result);
}

int		modify_magic_line(t_data *data)
{
  int		fd;
  char		*buffer;
  char		c;

  if ((fd = open("/tmp/magic_file", O_RDONLY)) == ERROR)
    return (ERROR);
  buffer = NULL;
  buffer = my_mallok(buffer, sizeof(char));
  buffer[0] = '\0';
  while (read(fd, &c, 1) > 0)
    buffer = my_strcat(buffer, "\0", c);
  close(fd);
  data->shell.tmp_magic = change_magic_result(data->shell.tmp_magic, buffer);
  return (SUCCESS);
}

int		loop_magic(t_data *data, char **tabo)
{
  pid_t		cpid;
  int		status;
  int		j;
  int		fd;

  j = 0;
  while (tabo[j] != NULL)
    {
      if ((fd = open("/tmp/magic_file", O_CREAT | O_RDWR \
		     | O_TRUNC, S_IRWXU)) == ERROR)
	return (ERROR);
      if ((cpid = fork()) == ERROR)
	return (ERROR);
      if (cpid == 0)
	{
	  if ((dup2(fd, 1)) == ERROR)
	    return (ERROR);
	  data->shell.line = my_strcpy(tabo[j]);
	  if (inhib(data) != ERROR)
	    if (parser_sep(data) != STOP)
	      {
		sep_loop(data);
		my_free_loop(data);
	      }
	  close(fd);
	  exit(1);
	}
      else
	if (waitpid(cpid, &status, WUNTRACED | WCONTINUED) == -1)
	  return (ERROR);
      if (modify_magic_line(data) == ERROR)
	return (ERROR);
      j++;
    }
  return (SUCCESS);
}

int		magic_quotes(t_data *data)
{
  int		cmpt;
  char		**tabo;

  cmpt = count_occurrence(data->shell.line, '`');
  if (cmpt == 0)
    return (STOP);
  if (cmpt % 2 == 1)
    return (my_put_error(MAGIC_ERROR, 1));
  data->shell.chk_magic = 1;
  data->shell.tmp_magic = my_strcpy(data->shell.line);
  tabo = my_magic_wordtab(data->shell.line, cmpt);
  if ((loop_magic(data, tabo)) == ERROR)
    return (ERROR);
  data->shell.line = my_strcpy(data->shell.tmp_magic);
  free(data->shell.tmp_magic);
  return (SUCCESS);
}
