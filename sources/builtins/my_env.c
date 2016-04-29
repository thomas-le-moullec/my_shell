/*
** my_env.c for my_env in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 16:36:55 2016 Thomas CHABOT
** Last update Wed Apr 27 15:51:21 2016 Thomas CHABOT
*/

#include "42sh.h"

int		my_env(t_data *data)
{
  if (data->shell.env != NULL)
    my_show_tab(data->shell.env);
  return (SUCCESS);
}
