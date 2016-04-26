/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 13:58:51 2016 Thomas CHABOT
** Last update Tue Apr 26 14:57:14 2016 Thomas CHABOT
*/

#include "42sh.h"

int		check_flags(char c, char *flags)
{
  int		i;

  i = 0;
  while (flags[i] != '\0')
    {
      if (c != flags[i])
	return (ERROR);
      i++;
    }
  return (SUCCESS);
}

int		count_words(char *str, char *flags)
{
  int		i;
  int		nb_words;

  i = 0;
  nb_words = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && check_flags(str[i], flags) == SUCCESS)
	i++;
      while (str[i] != '\0' && check_flags(str[i], flags) == ERROR)
	i++;
      if (i > 0 && check_flags(str[i], flags) == SUCCESS \
	  && check_flags(str[i - 1], flags) == ERROR)
	nb_words += 1;
      if (str[i] = '\0' && check_flags(str[i - 1], flags) == ERROR)
	nb_words += 1;
    }
  return (nb_words);
}

char		**my_str_to_wordtab(char *str, char *flags)
{
  int		i;
  int		j;
  int		k;
  char		**tab;

  i = 0;
  k = 0;
  tab = NULL;
  tab = my_mallok(tab, count_words(str, flags) + 1);
  while (str[i] != '\0')
    {
      j = 0;
      tab[k] = NULL;
      tab[k] = my_mallok(tab[k], count_words(str, flags) + 1);
      while (str[i] != '\0' && check_flags(str[i], flags) == SUCCESS)
	i++;
      while (str[i] != '\0' && check_flags(str[i], flags) == ERROR)
	tab[k][j++] = str[i++];
      tab[k++][j] = '\0';
    }
  tab[k] = NULL;
  return (tab);
}
