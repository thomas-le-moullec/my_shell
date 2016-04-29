/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 13:58:51 2016 Thomas CHABOT
** Last update Wed Apr 27 17:22:25 2016 Thomas CHABOT
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
  nb_words = 1;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && check_flags(str[i], flags) == SUCCESS)
	i++;
      while (str[i] != '\0' && check_flags(str[i], flags) == ERROR)
	i++;
      if (str[i] != '\0')
	nb_words++;
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
  tab = my_mallok_tab(tab, count_words(str, flags) + 1);
  while (str[i] != '\0')
    {
      j = 0;
      tab[k] = NULL;
      tab[k] = my_mallok(tab[k], my_strlen(str) + 1);
      while (str[i] != '\0' && check_flags(str[i], flags) == SUCCESS)
	i++;
      while (str[i] != '\0' && check_flags(str[i], flags) == ERROR)
	tab[k][j++] = str[i++];
      tab[k++][j] = '\0';
    }
  tab[k] = NULL;
  return (tab);
}
