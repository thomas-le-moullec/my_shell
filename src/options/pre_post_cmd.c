/*
** pre_post_cmd.c for pre_post_cmd in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Fri Jun  3 13:55:21 2016 leo LE DIOURON
** Last update Sat Jun  4 19:59:56 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

void		postcmd(t_data data)
{
  char          *result;

  result = NULL;
  if ((result = check_in_alias(&data, "postcmd")) != NULL)
    {
      init_shell(&data);
      data.shell.line = my_strcpy(result);
      parser_line(&data);
    }
}

void		precmd(t_data data)
{
  char          *result;

  result = NULL;
  if ((result = check_in_alias(&data, "precmd")) != NULL)
    {
      init_shell(&data);
      data.shell.line = my_strcpy(result);
      parser_line(&data);
    }
}
