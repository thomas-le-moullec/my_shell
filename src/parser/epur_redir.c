/*
** epur_redir.c for epur_redir in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 15:18:44 2016 leo LE DIOURON
** Last update Sat Jun  4 20:42:00 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

char		*epur_redir(char *str, int i)
{
  int		j;
  char		*result;

  result = NULL;
  result = my_mallok(result, sizeof(*result) * (my_strlen(str) + 1));
  j = 0;
  while (str[j] != '\0' && j != i)
    {
      result[j] = str[j];
      j++;
    }
  i++;
  if (str[i] == '>' || str[i] == '<')
    i++;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' \
	 && str[i] != '>' && str[i] != '<')
    i++;
  while (str[i] != '\0')
    result[j++] = str[i++];
  result[j] = '\0';
  my_free(str);
  return (result);
}
