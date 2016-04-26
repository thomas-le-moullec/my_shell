/*
** 42sh.h for 42sh in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 09:15:14 2016 Thomas CHABOT
** Last update Tue Apr 26 09:38:41 2016 Thomas CHABOT
*/

#ifndef SH42_H_
# define SH42_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include "struct.h"

/* **************** MYLIB ****************** */

void		my_putchar(char);

void		my_putstr(char *);

int		my_strlen(char *);

void		my_show_tab(char **);

int		count_tab(char **);

#endif /* SH42_H_ */
