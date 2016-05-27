/*
** color.c for color in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Fri May 27 16:11:46 2016 Thomas CHABOT
** Last update Fri May 27 16:26:58 2016 Thomas CHABOT
*/

#include "42sh.h"

char		**get_color(char **tabo)
{
  char		**new_tabo;
  int		i;

  i = 0;
  new_tabo = NULL;
  new_tabo = my_mallok(new_tabo, sizeof(*tabo) * (count_tab(tabo) + 2));
  while (tabo[i])
    {
      new_tabo[i] = my_strcpy(tabo[i]);
      i++;
    }
  new_tabo[i++] = my_strcpy("--color");
  new_tabo[i] = NULL;
  my_free_tab(tabo);
  return (new_tabo);
}
