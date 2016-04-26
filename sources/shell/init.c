/*
** init.c for init in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 12:51:48 2016 Thomas CHABOT
** Last update Tue Apr 26 12:59:38 2016 Thomas CHABOT
*/

#include "42sh.h"

void		init_shell(t_data *data)
{
  memset(data->shell, 0, sizeof(data->shell));
  if (data->shell.env == NULL)
    printf("env est NULL\n");
}
