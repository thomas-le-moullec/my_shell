/*
** 42sh.h for 42sh in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 09:15:14 2016 Thomas CHABOT
** Last update Tue Apr 26 18:35:48 2016 leo LE DIOURON
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
#include <string.h>
#include "struct.h"

/* **************** SHELL ****************** */

/* shell.c */
int		args_loop(t_data *);
int		cond_loop(t_data *);
int		sep_loop(t_data *);
int		my_shell(t_data *);

/* get_env.c */
int		get_env(t_data *, char **);

/* init.c */
void		get_home(t_data *);
void		get_old_pwd(t_data *);
void		get_pwd(t_data *);
void		init_shell(t_data *);

/* **************** EXEC ****************** */

/* exec.c */
int		exec(t_data *);

/*my_builtins.c */
int		my_builtins(t_data *);

/* **************** BUILTINS ****************** */

/* my_cd */
char		*check_cd(t_data *);
int		my_cd(t_data *);

/* my_exit */
int		my_env(t_data *);

/* my_setenv.c */
int		fill_env_none(t_data *);
int		check_env_exist(t_data *, char *);
char		**fill_env(t_data *, int);
int		setenv_empty(t_data *, int);
int		my_setenv(t_data *);

/* my_env.c */
int		my_exit(t_data *);

/* my_unsetenv.c */
int		unsetenv_loop(t_data *, int);
int		my_unsetenv(t_data *);

/* **************** PARSER ****************** */

/* parser.c */
int	        parser_cond(t_data *);
int		parser_sep(t_data *);

/* take_redir.c */
int		chek_redir_in(char *);
int		chek_redir_out(char *);
int		take_outfile(char *, int);
int		take_intfile(char *, int);
int		take_redir(t_data *, int);

/* **************** ERROR ****************** */

/* **************** DISP ****************** */

/* prompt.c */
void		disp_prompt(t_data *);

/* **************** MYLIB ****************** */

void		my_putchar(char, int);

void		my_putstr(char *, int);

void		my_put_nbr(int, int);

int		my_getnbr(char *);

int		my_strlen(char *);

void		my_show_tab(char **);

int		count_tab(char **);

char		*my_strcpy_equal(char *, char *);
char		*my_strcpy_full(char *, char *);
char		*my_strcpy_empty(char *);
char		*my_strcpy(char *);

char            *get_next_line();
char		*mallc_line(char *);

char		*my_epur_str(char *);

int		my_strcmp_equal(char *, char*);
int		my_strcmp(char *, char*);

void		my_free_tab(char **);
int		my_free_loop(t_data *);
void		my_free(void *);

void		*my_mallok(void *, int);

int		check_flags(char, char *);
int		count_words(char *);
char		**my_str_to_wordtab(char *, char *);

int		check_cond(char, char, char *);
char		**my_cond_to_wordtab(char *, char *);

#endif /* SH42_H_ */
