/*
** seg_fault.c for seg_fault in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sat Apr 30 14:39:02 2016 leo LE DIOURON
** Last update Tue May 17 09:44:36 2016 leo LE DIOURON
*/

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
  av[2] = NULL;
  printf("%s\n", av[1]);
  printf("%c\n", av[2][1]);
  return (0);
}
