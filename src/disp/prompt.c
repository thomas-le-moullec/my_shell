/*
** prompt.c for prompt in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 13:42:34 2016 Thomas CHABOT
** Last update Tue Apr 26 13:45:57 2016 Thomas CHABOT
*/

#include "42sh.h"

void		disp_prompt(t_data *data)
{
  if (data->shell.pwd != NULL)
    my_putstr(data->shell.pwd, 1);
  else
    my_putstr("/$", 1);
  my_putstr("> ", 1);
}
