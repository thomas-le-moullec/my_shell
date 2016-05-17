/*
** error_builtins.c for error_builtins in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Mon May 16 14:34:21 2016 Thomas CHABOT
** Last update Mon May 16 14:40:56 2016 Thomas CHABOT
*/

#include "42sh.h"

int		error_unsetenv()
{
  write(1, "unsetenv: Too few arguments.\n", 29);
  return (ERROR);
}

int		error_setenv()
{
  write(1, "setenv: Too many arguments.\n", 28);
  return (ERROR);
}
