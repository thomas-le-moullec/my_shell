/*
** magics_tools.c for magics_tools in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Thu Jun  2 14:12:07 2016 leo LE DIOURON
** Last update Thu Jun  2 14:13:50 2016 leo LE DIOURON
*/

#include "42sh.h"

char            **my_magic_wordtab(char *str, int cmpt, int i)
{
  char          **tabo;
  int           x;
  int           y;

  tabo = NULL;
  y = 0;
  tabo = my_mallok(tabo, sizeof(char *) * (cmpt + 1));
  while (str[i] != '\0')
    {
      x = 0;
      if (str[i] == '`')
        {
          i++;
          tabo[y] = my_mallok(tabo[y], sizeof(char) * (my_strlen(str) + 1));
          while (str[i] != '\0' && str[i] != '`')
            tabo[y][x++] = str[i++];
          tabo[y][x] = '\0';
          y++;
        }
      if (str[i] != '\0')
        i++;
    }
  tabo[y] = NULL;
  return (tabo);
}

char            *epur_return_line(char *str)
{
  int           i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
        str[i] = ' ';
      i++;
    }
  return (str);
}

int             modify_magic_line(t_data *data)
{
  int           fd;
  char          *buffer;
  char          c;

  if ((fd = open("/tmp/magic_file", O_RDONLY)) == ERROR)
    return (ERROR);
  buffer = NULL;
  buffer = my_mallok(buffer, sizeof(char));
  buffer[0] = '\0';
  while (read(fd, &c, 1) > 0)
    buffer = my_strcat(buffer, "\0", c);
  close(fd);
  data->shell.tmp_magic = change_magic_result(data->shell.tmp_magic, buffer);
  return (SUCCESS);
}
