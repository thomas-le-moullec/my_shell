/*
** my_free.c for my_free in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 10:35:36 2016 Thomas CHABOT
** Last update Tue Apr 26 10:36:35 2016 Thomas CHABOT
*/

#include "42sh.h"

void		my_free(void *ptr)
{
  if (ptr != NULL)
    {
      free(ptr);
      ptr = NULL;
    }
}
