/*
** my_cond_to_wordtab.c for my_cond_to_wordtab in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 14:51:13 2016 Thomas CHABOT
** Last update Tue May 17 17:47:26 2016 Hervé TCHIKLADZE
*/

#include "42sh.h"

int             check_cond(char c, char d, char *flags)
{
  int           i;

  i = 0;
  while (flags[i] != '\0')
    {
      if (c == flags[i] && d == flags[i])
        return (SUCCESS);
      i++;
    }
  return (ERROR);
}

int		count_words_cond(char *str)
{
  int		i;
  int		nb_words;

  i = 0;
  nb_words = 1;
  while (str[i] != '\0')
    {
      if (str[i] == '|')
	if (str[++i] == '|')
	  {
	    nb_words++;
	    i++;
	  }
      if (str[i] == '&')
	if (str[++i] == '&')
	  {
	    nb_words++;
	    i++;
	  }
      if (str[i] != '\0')
	i++;
    }
  return (nb_words);
}

char            **my_cond_to_wordtab(char *str, char *flags, int i)
{
  int           j;
  int           k;
  char          **tabo;

  k = 0;
  tabo = NULL;
  tabo = my_mallok(tabo, (count_words_cond(str) + 1) * sizeof(char *));
  while (str[i] != '\0')
    {
      j = 0;
      tabo[k] = NULL;
      tabo[k] = my_mallok(tabo[k], my_strlen(str) + 1);
      while (str[i] != '\0' \
	     && check_cond(str[i], str[i + 1], flags) == SUCCESS)
	i = i + 2;
      while (str[i] != '\0' \
	     && check_cond(str[i], str[i + 1], flags) == ERROR)
        tabo[k][j++] = str[i++];
      if (str[i] != '\0' && check_cond(str[i], str[i + 1], flags) == ERROR)
	i++;
      tabo[k++][j] = '\0';
    }
  tabo[k] = NULL;
  return (tabo);
}
