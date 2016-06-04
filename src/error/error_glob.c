/*
** error_glob.c for error_glob in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Sun May 29 14:25:57 2016 Thomas CHABOT
** Last update Sat Jun  4 19:26:02 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

int             glob_error(const char *path, int error)
{
  (void)path;
  (void)error;
  my_putstr(ERR_GLOB, 1);
  return (SUCCESS);
}
