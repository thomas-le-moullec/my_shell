/*
** my_strlen.c for my_strlen in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 09:32:01 2016 Thomas CHABOT
** Last update Tue Apr 26 09:33:02 2016 Thomas CHABOT
*/

#include "42sh.h"

int     my_strlen(char  *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
