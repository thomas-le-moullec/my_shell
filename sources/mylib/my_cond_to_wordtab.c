/*
** my_cond_to_wordtab.c for my_cond_to_wordtab in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 14:51:13 2016 Thomas CHABOT
** Last update Tue Apr 26 14:56:43 2016 Thomas CHABOT
*/

#include "42sh.h"

int             check_cond(char c, char d, char *flags)
{
  int           i;

  i = 0;
  while (flags[i] != '\0')
    {
      if (c != flags[i] && d != flags[i])
        return (ERROR);
      i++;
    }
  return (SUCCESS);
}

char            **my_cond_to_wordtab(char *str, char *flags)
{
  int           i;
  int           j;
  int           k;
  char          **tab;

  i = 0;
  k = 0;
  tab = NULL;
  tab = my_mallok(tab, count_words(str, flags) + 1);
  while (str[i] != '\0')
    {
      j = 0;
      tab[k] = NULL;
      tab[k] = my_mallok(tab[k], count_words(str, flags) + 1);
      while (str[i] != '\0' && str[i + 1] != '\0' \
	     && check_cond(str[i], str[i + 1], flags) == SUCCESS)
        i++;
      while (str[i] != '\0' && str[i + 1] != '\0' \
	     && check_cond(str[i], str[i + 1], flags) == ERROR)
        tab[k][j++] = str[i++];
      tab[k++][j] = '\0';
    }
  tab[k] = NULL;
  return (tab);
}
