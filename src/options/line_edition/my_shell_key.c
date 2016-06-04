/*
** my_shell_key.c for key in /home/payrau_a/rendu/aProjets/PSU/PSU_2015_42sh/src/options
** 
** Made by steeve payraudeau
** Login   <payrau_a@epitech.net>
** 
** Started on  Tue May 31 19:48:27 2016 steeve payraudeau
** Last update Sat Jun  4 21:00:40 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

static int		found_key(t_data *data, char *buffer, int *j)
{
  int			i;

  i = 0;
  while (data->tab_key[i].key != NULL)
    {
      if (my_strcmp(data->tab_key[i].key, buffer) == SUCCESS)
	{
	  if (data->tab_key[i].function(data, j) == ERROR)
	    return (STOP);
	  return (SUCCESS);
	}
      i++;
    }
  return (ERROR);
}

static int		laboratory_key(t_data *data, char *buffer, int *i)
{
  int			err;
  char			*tmp;

  err = ERROR;
  tmp = NULL;
  if ((err = found_key(data, buffer, i)) == STOP)
    return (STOP);
  if (err == ERROR && buffer[0] >= ' ' && buffer[0] <= '~')
    {
      data->shell.line = cp_str(data->shell.line, buffer, *i);
      data->shell.tmp_hist = my_free(data->shell.tmp_hist);
      data->shell.tmp_hist = my_strcpy(data->shell.line);
      if ((tmp = tgetstr("im", NULL)) == NULL)
	exit(1);
      my_putstr(tmp, 1);
      tmp = NULL;
      my_putstr(buffer, 1);
      if ((tmp = tgetstr("ei", NULL)) == NULL)
	exit(1);
      my_putstr(tmp, 1);
      (*i)++;
    }
  return (SUCCESS);
}

static int		catch_key(t_data *data)
{
  char			buffer[8];
  int			nbr;
  int			i;

  nbr = 0;
  i = 0;
  while ((nbr = read(0, buffer, 8)) > 0 && buffer[0] != '\n')
    {
      if (nbr <= 0)
      	return (ERROR);
      buffer[nbr] = '\0';
      if (laboratory_key(data, buffer, &i) == STOP)
	return (ERROR);
    }
  while (data->hist != NULL && data->hist->next != NULL)
    data->hist = data->hist->next;
  my_putstr("\n", 1);
  return (SUCCESS);
}

static int		my_shell_key_loop(t_data *data)
{
  if (mode_canon(1) == ERROR)
    return (ERROR);
  if (periodic(data) == ERROR)
    return (ERROR);
  postcmd(*data);
  if (data->shell.line != NULL)
    if (parser_line(data) == ERROR)
      return (ERROR);
  precmd(*data);
  if ((mode_canon(0)) == ERROR)
    return (ERROR);
  disp_prompt(data);
  data->shell.pos_list = 0;
  data->shell.line = my_free(data->shell.line);
  data->shell.line = my_strcpy("\0");
  data->shell.tmp_hist = my_free(data->shell.tmp_hist);
  data->shell.tmp_hist = my_strcpy("\0");
  return (SUCCESS);
}

int		my_shell_key(t_data *data)
{
  if (init_term(data) == ERROR)
    exit(0);
  if ((mode_canon(0)) == ERROR)
    return (ERROR);
  disp_prompt(data);
  while (catch_key(data) != ERROR)
    if (my_shell_key_loop(data) == ERROR)
      return (ERROR);
  if ((mode_canon(1)) == ERROR)
    return (ERROR);
  my_putstr(EXIT_THIS, 1);
  data->shell.line = my_free(data->shell.line);
  data->shell.tmp_hist = my_free(data->shell.tmp_hist);
  return (SUCCESS);
}
