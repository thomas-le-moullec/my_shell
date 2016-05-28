/*
** error_quote.c for error_quote in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 15:54:53 2016 Hervé TCHIKLADZE
** Last update Fri May 27 15:37:56 2016 Thomas CHABOT
*/

#include "42sh.h"

void		*error_quote(t_data *data, char c)
{
  my_putstr("Unmatched ", 1);
  my_putchar(c, 1);
  my_putstr(".\n", 1);
  data->shell.exit_status = 1;
  return (NULL);
}
