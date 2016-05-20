/*
** count_size_line_file.c for count_size_line_file.c in /home/payrau_a/rendu/aProjets/PSU/PSU_2015_42sh
** 
** Made by steeve payraudeau
** Login   <payrau_a@epitech.net>
** 
** Started on  Wed May 18 16:52:35 2016 steeve payraudeau
** Last update Wed May 18 17:33:13 2016 steeve payraudeau
*/

#include "42sh.h"

int		count_size_line_file(int fd, int size)
{
  char		buff[1];

  while (read(fd, buff, 1) > 0)
    size++;
  return (size);
}
