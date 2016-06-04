/*
** glob.c for glob in /home/payrau_a/rendu/aProjets/PSU/PSU_2015_42sh/src/options
** 
** Made by steeve payraudeau
** Login   <payrau_a@epitech.net>
** 
** Started on  Sat May 28 15:40:07 2016 steeve payraudeau
** Last update Sat Jun  4 19:49:39 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static int		check_hook(char *str)
{
  int			i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '[')
	{
	  while (str[i] != '\0' && str[i] != ']')
	    i++;
	  if (str[i] == ']')
	    return (SUCCESS);
	  return (ERROR);
	}
      i++;
    }
  return (ERROR);
}

static int		check_stars(char *str)
{
  int			i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '*' || str[i] == '?')
	return (SUCCESS);
      i++;
    }
  return (ERROR);
}

static char		**take_tab_stars(char *str, char *str_err, \
					 t_data *data)
{
  glob_t		tab_glob;
  int			err;

  err = glob(str, 0, glob_error, &tab_glob);
  if (err != 0)
    {
      my_putstr(str_err, 1);
      my_putstr(NO_MATCH, 1);
      data->shell.exit_status = 1;
      return (NULL);
    }
  return (tab_glob.gl_pathv);
}

static char		**replace_stars(t_data *data, int *j)
{
  char			**tabo;
  char			**result;
  int			i;
  int			k;

  i = -1;
  k = 0;
  result = NULL;
  if ((tabo = take_tab_stars(data->parser.tab_args[(*j)],
			     data->parser.tab_args[0], data)) == NULL)
    return (NULL);
  result = my_mallok(result, sizeof(*result) *
		     (count_tab(tabo) + count_tab(data->parser.tab_args) + 1));
  while (data->parser.tab_args[++i] != NULL && i < (*j))
    result[i] = my_strcpy(data->parser.tab_args[i]);
  while (tabo[k] != NULL)
    result[i++] = my_strcpy(tabo[k++]);
  k = (*j) + 1;
  (*j) = i;
  while (data->parser.tab_args[k] != NULL)
    result[i++] = my_strcpy(data->parser.tab_args[k++]);
  result[i] = NULL;
  my_free_tab(tabo);
  my_free_tab(data->parser.tab_args);
  return (result);
}

int		my_glob(t_data *data)
{
  int		j;

  j = 0;
  while (data->parser.tab_args[j] != NULL)
    {
      if (check_stars(data->parser.tab_args[j]) == SUCCESS ||
	  check_hook(data->parser.tab_args[j]) == SUCCESS)
	{
	  if ((data->parser.tab_args = replace_stars(data, &j)) == NULL)
	    return (ERROR);
	}
      else
	j++;
    }
  return (SUCCESS);
}
