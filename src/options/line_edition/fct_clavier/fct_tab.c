/*
** fct_down.c for down in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh/sources/options/fct_clavier
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 17:21:34 2016 Hervé TCHIKLADZE
** Last update Fri Jun  3 16:50:16 2016 leo LE DIOURON
*/

#include "42sh.h"

char		*my_strcpy_posi(t_data *data, int i)
{
  char		*new;
  int		us;
  int		tmp;

  tmp = i;
  us = 0;
  new = NULL;
  new = my_mallok(new, sizeof(*new));
  new[0] = '\0';
  found_positions(data->shell.line, i, &tmp, &us);
  while (tmp < i && data->shell.line[tmp] != '\0')
    {
      new = strcop_char(&new, data->shell.line[tmp]);
      tmp++;
    }
  return (new);
}

char		**my_autocomplete(char *str)
{
  glob_t	tab_glob;
  int		err;

  err = glob(str, GLOB_MARK | GLOB_ERR, NULL, &tab_glob);
  if (err != 0)
    return (NULL);
  return (tab_glob.gl_pathv);
}

int		print_list_auto(t_data *data, char **tabo)
{
  char		buffer[2];
  int		nbr;
  int		size;

  my_putstr("\n", 1);
  buffer[0] = '\0';
  if ((nbr = count_tab(tabo)) > 30)
    {
      my_putstr("There are ", 1);
      my_put_nbr(nbr, 1);
      my_putstr(" rows, list them anyway? [n/y] ", 1);
      if ((size = read(0, buffer, 1)) <= 0)
	return (ERROR);
      buffer[size] = '\0';
      my_putstr(buffer, 1);
      my_putstr("\n", 1);
    }
  if (nbr <= 30 || (buffer != NULL && buffer[0] == 'y'))
    my_show_tab(tabo);
  disp_prompt(data);
  if (data->shell.line != NULL)
    my_putstr(data->shell.line, 1);
  return (SUCCESS);
}

int             fct_tab(t_data *data, int *i)
{
  char		**tabo;
  char		*tmp;

  tmp = NULL;
  if (data->shell.line != NULL)
    if ((tmp = my_strcpy_posi(data, *i)) == NULL)
      return (SUCCESS);
  tmp = strcop_char(&tmp, '*');
  if ((tabo = my_autocomplete(tmp)) != NULL &&
      found_tabo_comp(tabo, data->shell.line) == SUCCESS)
    {
      if (count_tab(tabo) > 1)
	print_list_auto(data, tabo);
      else
	print_autocompletion(data, tabo[0], i);
      reinit_cursor(data, *i);
    }
  return (SUCCESS);
}
