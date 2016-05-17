/*
** my_malloc.c for my_malloc in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 10:37:17 2016 Thomas CHABOT
** Last update Sat Apr 30 16:20:48 2016 leo LE DIOURON
*/

#include "42sh.h"

void		*my_mallok(void *ptr, int size)
{
  if (!(ptr = malloc(size)))
    exit(ERROR);
  return (ptr);
}
