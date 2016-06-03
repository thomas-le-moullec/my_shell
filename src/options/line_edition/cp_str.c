/*
** cp_str.c for lala in /home/payrau_a/rendu/aProjets/PSU/PSU_2015_42sh/src/options/line_edition
** 
** Made by steeve payraudeau
** Login   <payrau_a@epitech.net>
** 
** Started on  Wed Jun  1 16:08:54 2016 steeve payraudeau
** Last update Fri Jun  3 21:20:56 2016 Thomas CHABOT
*/

#include "42sh.h"

char            *strcop_char(char **str, char c)
{
  char          *back;
  int           i;

  i = 0;
  back = NULL;
  if ((*str) == NULL)
    {
      back = my_mallok(back, 2 * sizeof(*back));
      back[0] = c;
      back[1] = '\0';
    }
  else
    {
      back = my_mallok(back, (my_strlen((*str)) + 2) * sizeof(*back));
      while ((*str)[i] != '\0')
	{
	  back[i] = (*str)[i];
	  i++;
	}
      back[i++] = c;
      back[i] = '\0';
      (*str) = my_free((*str));
    }
  return (back);
}

char		*cp_str(char *str, char *new, int pos)
{
  char		*tmp;
  int		i;
  int		j;

  i = 0;
  j = 0;
  tmp = NULL;
  if (str == NULL)
    while (new[i] != '\0')
      str = strcop_char(&str, new[i++]);
  else
    {
      while (i < pos && str[i] != '\0')
	tmp = strcop_char(&tmp, str[i++]);
      while (new[j] != '\0')
	tmp = strcop_char(&tmp, new[j++]);
      while (str[i] != '\0' && i < my_strlen(str))
	tmp = strcop_char(&tmp, str[i++]);
      str = my_free(str);
      return (tmp);
    }
  return (str);
}
