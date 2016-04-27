/*
** my_env.c for my_env in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 16:36:55 2016 Thomas CHABOT
** Last update Tue Apr 26 16:38:46 2016 Thomas CHABOT
*/

#include "42sh.h"

void		my_env(t_data *data)
{
  if (data->shell.env != NULL)
    my_show_tab(data->shell.env);
}
