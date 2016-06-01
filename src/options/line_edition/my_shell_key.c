/*
** my_shell_key.c for key in /home/payrau_a/rendu/aProjets/PSU/PSU_2015_42sh/src/options
** 
** Made by steeve payraudeau
** Login   <payrau_a@epitech.net>
** 
** Started on  Tue May 31 19:48:27 2016 steeve payraudeau
** Last update Wed Jun  1 18:21:43 2016 steeve payraudeau
*/

#include "42sh.h"

int		found_key(t_data *data, char *buffer, int *j)
{
  int		i;

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

int		laboratory_key(t_data *data, char *buffer, int *i)
{
  int		err;

  err = ERROR;
  if (data->shell.line != NULL)
    if ((err = found_key(data, buffer, i)) == STOP)
      return (STOP);
  if (err == ERROR && buffer[0] >= ' ' && buffer[0] <= '~')
    {
      data->shell.line = cp_str(data->shell.line, buffer);
      my_putstr(tgetstr("im", NULL), 1);
      my_putstr(buffer, 1);
      my_putstr(tgetstr("ei", NULL), 1);
      (*i)++;
    }
  return (SUCCESS);
}

int		catch_key(t_data *data)
{
  char		buffer[8];
  int		nbr;
  int		i;

  nbr = 0;
  i = 0;
  while ((nbr = read(0, buffer, 8)) > 0 && buffer[0] != '\n')
    {
      if (nbr <= 0)
      	return (ERROR);
      buffer[nbr] = '\0';
      if (laboratory_key(data, buffer, &i) == STOP)
	return (STOP);
    }
  /*historique*/
  my_putstr("\n", 1);
  return (SUCCESS);
}

int		my_shell_key(t_data *data)
{
  if (init_term(data) == ERROR)
    exit(0);
  mode_canon(0);
  disp_prompt(data);
  data->shell.line = NULL;
  while (catch_key(data) != ERROR)
    {
      if (parser_line(data) == ERROR)
	{
	  mode_canon(1);
	  return (ERROR);
	}
      disp_prompt(data);
      data->shell.line = NULL;
    }
  mode_canon(1);
  my_putstr("exit\n", 1);
  return (SUCCESS);
}