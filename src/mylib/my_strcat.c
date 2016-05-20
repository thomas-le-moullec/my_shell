/*
** my_strcat.c for my_strcat in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Apr 29 13:44:08 2016 leo LE DIOURON
** Last update Fri Apr 29 13:49:54 2016 leo LE DIOURON
*/

#include "42sh.h"

char	*my_strcat(char *one, char *two, char c)
{
  int	i;
  int	j;
  char	*result;

  i = 0;
  j = 0;
  result = NULL;
  result = my_mallok(result, my_strlen(one) + my_strlen(two) + 2);
  while (one[i] != '\0')
    result[j++] = one[i++];
  if (c != 0)
    result[j++] = c;
  i = 0;
  while (two[i] != '\0')
    result[j++] = two[i++];
  result[j] = '\0';
  return (result);
}
