/*
** my_free_alias.c for my_free_alias in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Wed May 25 15:31:19 2016 leo LE DIOURON
** Last update Wed May 25 15:37:03 2016 leo LE DIOURON
*/

#include "42sh.h"

void	my_free_alias(t_alias *alias)
{
  printf("1\n");
  if (alias != NULL)
    {
      printf("2\n");
      while (alias->prev != NULL)
	{
	  printf("3\n");
	  alias = alias->prev;
	  alias->next->cmd = my_free(alias->next->cmd);
	  alias->next->name = my_free(alias->next->name);
	  alias->next = my_free(alias->next);
	}
      alias->cmd = my_free(alias->cmd);
      alias->name = my_free(alias->name);
      alias = my_free(alias);
    }
}
