/*
** ambigous.c for ambigous in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sun May  1 14:55:12 2016 leo LE DIOURON
** Last update Sun May  1 14:57:33 2016 leo LE DIOURON
*/

#include "42sh.h"

int		ambiguous(int type)
{
  if (type == 0)
    my_putstr("Ambiguous input redirect.\n", 1);
  else
    my_putstr("Ambiguous output redirect.\n", 1);
  return (ERROR);
}
