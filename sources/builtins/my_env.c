/*
** my_env.c for my_env in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 16:36:55 2016 Thomas CHABOT
** Last update Fri Apr 29 14:57:48 2016 leo LE DIOURON
*/

#include "42sh.h"

int		my_env(t_data *data)
{
  if (data->shell.env != NULL)
    my_show_tab(data->shell.env);
  return (SUCCESS);
}
