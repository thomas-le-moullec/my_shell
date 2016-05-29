/*
** error_glob.c for error_glob in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Sun May 29 14:25:57 2016 Thomas CHABOT
** Last update Sun May 29 14:27:29 2016 Thomas CHABOT
*/

#include "42sh.h"

int             glob_error(const char *path, int error)
{
  (void)path;
  (void)error;
  my_putstr("ERRROR GLOB\n", 1);
  return (0);
}
