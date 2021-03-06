/*
** var_env.c for var_env in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Mon May 16 16:50:31 2016 leo LE DIOURON
** Last update Sun Jun  5 14:45:09 2016 leo LE DIOURON
*/

#include "42sh.h"

static char		*take_var(t_data *data, int j, int i)
{
  int			a;
  int			k;
  char			*var_env;

  a = i;
  k = 0;
  var_env = NULL;
  while (data->parser.tab_pipe[j][i] != '\0' &&
	 data->parser.tab_pipe[j][i] != '\t' &&
	 data->parser.tab_pipe[j][i] != ' ')
    i++;
  var_env = my_mallok(var_env, sizeof(*var_env) * (i - a + 1));
  i = a;
  while (data->parser.tab_pipe[j][i] != '\0' &&
	 data->parser.tab_pipe[j][i] != '\t' &&
	 data->parser.tab_pipe[j][i] != ' ')
    var_env[k++] = data->parser.tab_pipe[j][i++];
  var_env[k] = '\0';
  return (var_env);
}

static void		creat_new_string(t_data *data, char *result, int j)
{
  char			*new_string;
  int			i;
  int			k;
  int			l;

  i = 0;
  l = 0;
  k = 0;
  new_string = NULL;
  new_string = my_mallok(new_string, sizeof(*new_string) * \
                         (my_strlen(data->parser.tab_pipe[j]) + \
                          my_strlen(result) + 1));
  while (data->parser.tab_pipe[j][i] && data->parser.tab_pipe[j][i] != '$')
    new_string[l++] = data->parser.tab_pipe[j][i++];
  while (result[k] != '\0')
    new_string[l++] = result[k++];
  while (data->parser.tab_pipe[j][i] != '\0' &&
	 data->parser.tab_pipe[j][i] != ' ' &&
	 data->parser.tab_pipe[j][i] != ' ')
    i++;
  while (data->parser.tab_pipe[j][i] != '\0')
    new_string[l++] = data->parser.tab_pipe[j][i++];
  new_string[l] = '\0';
  data->parser.tab_pipe[j] = my_strcpy(new_string);
  new_string = my_free(new_string);
}

static char		*take_var_local(t_data *data, char *var)
{
  char			*result;

  result = NULL;
  while (data->local->prev != NULL)
    data->local = data->local->prev;
  while (data->local->next != NULL)
    {
      if (my_strcmp(data->local->name, var) == SUCCESS)
	result = my_strcpy(data->local->cmd);
      data->local = data->local->next;
    }
  if (my_strcmp(data->local->name, var) == SUCCESS)
    result = my_strcpy(data->local->cmd);
  return (result);
}

static int		replace_string(t_data *data, int j, int i, char *v_e)
{
  int			nb;
  char			*res;

  res = NULL;
  nb = ERROR;
  if (((data->local == NULL) || (res = take_var_local(data, v_e)) == NULL) \
      && (nb = check_env_exist(data, v_e)) == ERROR)
    {
      data->parser.tab_pipe[j][i] = ' ';
      my_putstr(v_e, 1);
      my_putstr(UNDEF_VAR, 1);
      res = my_free(res);
      data->shell.exit_status = 1;
      return (ERROR);
    }
  if (nb != ERROR)
    res = my_strcpy_equal(data->shell.env[nb]);
  if (res == NULL || res[0] == '\0')
    {
      res = my_free(res);
      return (ERROR);
    }
  creat_new_string(data, res, j);
  res = my_free(res);
  return (SUCCESS);
}

int		var_env_loc(t_data *data, int j)
{
  int		i;
  char		*var_env;

  i = 0;
  var_env = NULL;
  while (data->parser.tab_pipe[j][i] != '\0')
    {
      if (data->parser.tab_pipe[j][i] == '$')
	{
	  var_env = take_var(data, j, i + 1);
	  if (replace_string(data, j, i, var_env) == ERROR)
	    return (ERROR);
	  var_env = my_free(var_env);
	  i = -1;
	}
      i++;
    }
  return (SUCCESS);
}
