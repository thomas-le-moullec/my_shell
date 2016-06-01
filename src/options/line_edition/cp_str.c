/*
** cp_str.c for lala in /home/payrau_a/rendu/aProjets/PSU/PSU_2015_42sh/src/options/line_edition
** 
** Made by steeve payraudeau
** Login   <payrau_a@epitech.net>
** 
** Started on  Wed Jun  1 16:08:54 2016 steeve payraudeau
** Last update Wed Jun  1 16:45:44 2016 steeve payraudeau
*/

#include <42sh.h>

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
      free((*str));
    }
  return (back);
}

char		*cp_str(char *str, char *new)
{
  int		i;

  i = 0;
  while (new[i] != '\0')
    str = strcop_char(&str, new[i++]);
  return (str);
}
