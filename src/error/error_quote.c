/*
** error_quote.c for error_quote in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 15:54:53 2016 Hervé TCHIKLADZE
** Last update Sat Jun  4 17:12:25 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

void		*error_quote(t_data *data, char c)
{
  my_putstr(ERR_QUOTE, 1);
  my_putchar(c, 1);
  my_putstr(".\n", 1);
  data->shell.exit_status = 1;
  return (NULL);
}
