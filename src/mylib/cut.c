/*
** cut.c for cut in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Mon May 23 15:25:15 2016 Hervé TCHIKLADZE
** Last update Mon May 23 15:29:01 2016 Hervé TCHIKLADZE
*/

#include "42sh.h"

char		*cut_extrem(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  str[i - 1] = '\0';
  str = &str[1];
  return (str);
}
