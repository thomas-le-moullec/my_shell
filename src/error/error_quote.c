/*
** error_quote.c for error_quote in /home/tchikl_h/rendu/B2/PSU/PSU_2015_42sh
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May 17 15:54:53 2016 Hervé TCHIKLADZE
** Last update Tue May 17 15:56:52 2016 Hervé TCHIKLADZE
*/

#include "42sh.h"

void		*error_quote(char c)
{
  my_putstr("Unmatched ", 1);
  my_putchar(c, 1);
  my_putstr(".\n", 1);
  return (NULL);
}
