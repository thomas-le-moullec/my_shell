/*
** magics.c for magics in /home/le-mou_t/rendu/PSU_2015_42sh/src/options
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Tue May 31 14:37:40 2016 Thomas LE MOULLEC
** Last update Thu Jun  2 14:25:02 2016 leo LE DIOURON
*/

#include "42sh.h"

char		*fill_result_magic(char *result, char *line, char *buffer)
{
  int		k;
  int		f;
  int		j;

  j = 0;
  f = 0;
  k = 0;
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
  return (result);
}

char		*change_magic_result(char *line, char *buffer)
{
  char          *result;

  result = NULL;
  result = my_mallok(result, sizeof(char) *
                     (my_strlen(line)
                      + my_strlen(buffer) + 1));
  result = fill_result_magic(result, line, buffer);
  free(line);
  free(buffer);
  result = epur_return_line(result);
  return (result);
}

int		exe_magic_quotes(t_data *data, char **tabo, int fd, int j)
{
  int		cpid;
  int		status;

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
  return (SUCCESS);
}

int		loop_magic(t_data *data, char **tabo)
{
  int		j;
  int		fd;

  j = 0;
  while (tabo[j] != NULL)
    {
      if ((fd = open("/tmp/magic_file", O_CREAT | O_RDWR \
		     | O_TRUNC, S_IRWXU)) == ERROR)
	return (ERROR);
      if (exe_magic_quotes(data, tabo, fd, j) == ERROR)
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
  tabo = my_magic_wordtab(data->shell.line, cmpt, 0);
  if ((loop_magic(data, tabo)) == ERROR)
    return (ERROR);
  data->shell.line = my_strcpy(data->shell.tmp_magic);
  free(data->shell.tmp_magic);
  return (SUCCESS);
}
