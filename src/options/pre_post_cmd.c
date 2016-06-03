/*
** pre_post_cmd.c for pre_post_cmd in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Jun  3 13:55:21 2016 leo LE DIOURON
** Last update Fri Jun  3 14:05:11 2016 leo LE DIOURON
*/

#include "42sh.h"

void	postcmd(t_data data)
{
  char          *result;

  if ((result = check_in_alias(&data, "postcmd")) != NULL)
    {
      data.shell.line = my_strcpy(result);
      parser_line(&data);
    }
}

void	precmd(t_data data)
{
  char          *result;

  if ((result = check_in_alias(&data, "precmd")) != NULL)
    {
      data.shell.line = my_strcpy(result);
      parser_line(&data);
    }
}
