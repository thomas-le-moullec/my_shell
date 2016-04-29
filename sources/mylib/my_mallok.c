/*
** my_malloc.c for my_malloc in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 10:37:17 2016 Thomas CHABOT
** Last update Wed Apr 27 17:12:14 2016 Thomas CHABOT
*/

#include "42sh.h"

char		**my_mallok_tab(char **ptr, int size)
{
  if (!(ptr = malloc(sizeof(*ptr) * size)))
    exit(ERROR);
  return (ptr);
}

void		*my_mallok(void *ptr, int size)
{
  if (!(ptr = malloc(sizeof(*ptr) * size)))
    exit(ERROR);
  return (ptr);
}
