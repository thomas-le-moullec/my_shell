/*
** history.c for history in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
**
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
**
** Started on  Tue May 17 16:05:48 2016 Hervé TCHIKLADZE
** Last update Sat Jun  4 11:29:15 2016 Hervé TCHIKLADZE
*/

#include "42sh.h"

char            *change_line_hist(t_data *data, char *tmp_hist, int y)
{
  int		i;
  int		f;
  int           k;
  char          *result;

  k = 0;
  i = 0;
  f = 0;
  result = NULL;
  result = my_mallok(result, sizeof(char) *
                     (my_strlen(data->parser.tab_pipe[y])
                      + my_strlen(data->hist->str) + 1));
  while (data->parser.tab_pipe[y][i] && data->parser.tab_pipe[y][i] != '!')
    result[k++] = data->parser.tab_pipe[y][i++];
  while (data->hist->str[f])
    result[k++] = data->hist->str[f++];
  f = 0;
  i++;
  while (data->parser.tab_pipe[y][i] && tmp_hist[f++])
    i++;
  while (data->parser.tab_pipe[y][i])
    result[k++] = data->parser.tab_pipe[y][i++];
  result[k] = '\0';
  my_free(data->parser.tab_pipe[y]);
  return (result);
}

char		*take_tmp_hist(t_data *data, int y, int i, int j)
{
  char		*result;

  result = NULL;
  result = my_mallok(result, sizeof(char) \
		     * (my_strlen(data->parser.tab_pipe[y]) + 1));
  while (data->parser.tab_pipe[y][i] && data->parser.tab_pipe[y][i] != '!')
    i++;
  if (data->parser.tab_pipe[y][i] == '\0')
    {
      result = my_free(result);
      return (NULL);
    }
  i++;
  while (data->parser.tab_pipe[y][i] && data->parser.tab_pipe[y][i] != ' ' \
	  && data->parser.tab_pipe[y][i] != '\t')
    result[j++] = data->parser.tab_pipe[y][i++];
  result[j] = '\0';
  if (j == 0)
    {
      result = my_free(result);
      return (NULL);
    }
  return (result);
}

t_hist		*add_elem_key(t_hist *list, char *str)
{
  t_hist	*new_elem;

  new_elem = NULL;
  new_elem = my_mallok(new_elem, sizeof(*new_elem));
  new_elem->str = my_strcpy(str);
  new_elem = get_time(new_elem);
  if (list == NULL)
    {
      new_elem->prev = NULL;
      new_elem->next = NULL;
      new_elem->pos = 1;
      return (new_elem);
    }
  new_elem->pos = list->pos + 1;
  new_elem->prev = list;
  new_elem->next = NULL;
  list->next = new_elem;
  return (new_elem);
}
