/*
** epur_redir.c for epur_redir in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 15:18:44 2016 leo LE DIOURON
** Last update Sat Apr 30 13:56:49 2016 leo LE DIOURON
*/

#include "42sh.h"

char		*epur_redir(char *str, int i)
{
  int		j;
  char		*result;

  result = NULL;
  result = my_mallok(result, my_strlen(str));
  j = 0;
  while (str[j] != '\0' && j != i)
    {
      result[j] = str[j];
      j++;
    }
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
