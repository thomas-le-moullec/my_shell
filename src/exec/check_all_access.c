/*
** check_all_access.c for check_all_access in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri May  6 10:35:51 2016 leo LE DIOURON
** Last update Tue May 24 16:06:01 2016 leo LE DIOURON
*/

#include "42sh.h"

char            *take_path_exec(char *str)
{
  int           i;
  int           a;
  char          *res;

  res = NULL;
  res = my_mallok(res, sizeof(char) * (my_strlen(str) + 1));
  i = 0;
  a = 0;
  while (str[i] != '\0')
    i++;
  while (i > 0 && str[i] != '/')
    i--;
  while (a < i)
    {
      res[a] = str[a];
      a++;
    }
  res[a] = '\0';
  return (res);
}
