/*
** main.c for main in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 09:08:44 2016 Thomas CHABOT
** Last update Tue Apr 26 13:32:40 2016 Thomas CHABOT
*/

#include "42sh.h"

int		main(int ac, char **av, char **ae)
{
  t_data	data;

  (void)av;
  if (ac != 1)
    return (ERROR);
  init_shell(&data);
  get_env(&data, ae);
  
  return (SUCCESS);
}
