/*
** 42sh.h for 42sh in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 09:15:14 2016 Thomas CHABOT
** Last update Tue Apr 26 10:53:29 2016 leo LE DIOURON
*/

#ifndef SH42_H_
# define SH42_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include "struct.h"

/* **************** MYLIB ****************** */

void		my_putchar(char, int);

void		my_putstr(char *, int);

void		my_put_nbr(int, int);

int		my_getnbr(char *);

int		my_strlen(char *);

void		my_show_tab(char **);

int		count_tab(char **);

char            *get_next_line();
char		*mallc_lien(char *);

char		*my_epur_str(char *);

int		my_strcmp(char *, char*);

void		my_free(void *);

void		*my_mallok(void *, int);

#endif /* SH42_H_ */
