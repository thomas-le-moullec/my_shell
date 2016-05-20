/*
** parser.c for parser in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 13:55:25 2016 Thomas CHABOT
** Last update Wed May  4 18:20:16 2016 Thomas CHABOT
*/

#include "42sh.h"

int		parser_sep(t_data *data)
{
  data->shell.line = my_epur_str(data->shell.line);
  if (data->shell.line == NULL)
    return (STOP);
  data->parser.tab_sep = my_str_to_wordtab(data->shell.line, ";");
  return (SUCCESS);
}
