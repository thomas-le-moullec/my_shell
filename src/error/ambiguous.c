/*
** ambigous.c for ambigous in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sun May  1 14:55:12 2016 leo LE DIOURON
** Last update Tue May 24 13:18:45 2016 Thomas CHABOT
*/

#include "42sh.h"

int		ambiguous(int type)
{
  if (type == 0)
    my_putstr("AMBI_INPUT", 1);
  else
    my_putstr("AMBI_OUTPUT", 1);
  return (ERROR);
}
