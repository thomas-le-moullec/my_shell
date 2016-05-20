/*
** 42sh.h for 42sh in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**#include <sys/stat.h>

** Started on  Tue Apr 26 09:15:14 2016 Thomas CHABOT
** Last update Fri May 20 13:37:31 2016 Hervé TCHIKLADZE
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
#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <term.h>
#include "struct.h"

/* **************** SHELL ****************** */

/* shell.c */
int		pipe_loop(t_data *);
int		cond_loop(t_data *);
int		sep_loop(t_data *);
int		my_shell(t_data *);

/* get_env.c */
int		get_env(t_data *, char **);

/* init.c */
int		get_path(t_data *);
int		get_home(t_data *);
int		get_old_pwd(t_data *);
int		get_pwd(t_data *);
int		init_shell(t_data *);

/* **************** EXEC ****************** */

/* exec.c */
int		check_str_access(char *);
int		my_exec(t_data *);

/*my_builtins.c */
int		my_builtins(t_data *);

/* execution.c */
int		father(pid_t, t_data *);
int		execution(t_data *);
int		access_path(t_data *);
int		exec_with_path(t_data *, int);
int		exec_without_path(t_data *);

/* redirection_outfile.c */
int		redirection_outfile(t_data *);

/* redirection_infile.c */
int		redirection_infile(t_data *);
int             double_infile_redir(t_data *);

/* in_and_out.c */
int		manage_all_redir(t_data *);
int		manage_pipe(t_data *);
int		in_and_out(t_data *);

/* make_pipe.c */
int		make_pipe(t_data *);

/* **************** BUILTINS ****************** */

/* my_cd */
char		*check_cd(t_data *);
int		my_cd(t_data *);

/* my_exit */
int		my_env(t_data *);

/* my_setenv.c */
int		check_env_exist(t_data *, char *);
int		setenv_empty(t_data *, int);
int		my_setenv(t_data *);

/* fill_env.c */
char		**fill_env_none(t_data *, char **, int);
char		**fill_env_loop(t_data *, int, char **, int);
char		**fill_env(t_data *, int);

/* my_env.c */
int		my_exit(t_data *);

/* my_unsetenv.c */
char		**unsetenv_loop(t_data *, int);
int		my_unsetenv(t_data *);

/* alias.c */
t_alias		*add_elem_alias(t_alias *alias, char *, char *);
int             init_list_alias(t_data *);

/* **************** PARSER ****************** */

/* parser.c */
int	        parser_cond(t_data *);
int		parser_sep(t_data *);

/* take_redir.c */
int		take_outfile(char *, int, t_data *);
int		take_infile(char *, int, t_data *);
int		manage_outfile(t_data *, int, int *);
int		manage_infile(t_data *, int, int *);

/* check_redir.c */
int		check_redir_in(char *);
int		check_redir_out(char *);

/* parser_redir.c */
int		parser_redir(t_data *, int);

/* epur_redir.c */
char		*epur_redir(char *, int);

/* take_nb_pipe.c */
void		take_nb_pipe(t_data *);

/*take_type_cond.c */
void		take_type_cond(t_data *, int, int, int);

/* **************** ERROR ****************** */

/* ambiguous.c */
int		ambiguous(int);

/* missing_name.c */
int		missing_name();

/* error_bultins.c */
int		error_unsetenv();
int		error_setenv();

/* error_quote.c */
void            *error_quote(char);

/* error_dir.c */
int             error_not_found(t_data *);
int             error_dir(t_data *);
int             error_perm(t_data *);

/* **************** DISP ****************** */

/* prompt.c */
void		disp_prompt(t_data *);

/* **************** OPTIONS ****************** */

/* var_env.c */
int		var_env(t_data *, int);
int		replace_string(t_data *, int, int, char *);
char		*take_var(t_data *, int, int);
void            creat_new_string(t_data *, char *, int);

/* inhib.c */
int             inhib(t_data *);
char            *modify_str(t_data *, char, int);
int             check_special_char(char, char *);
void            args_convert(t_data *);

/* history.c */
t_hist		*add_elem_key(t_hist *, char *);
void		print_list(t_hist *);

/* mode_canon.c */
int		mode_canon(int);

/* **************** FCT_CLAVIER ************** */

/* fct_up.c */
int		fct_up(t_data *);
/* fct_down.c */
int		fct_down(t_data *);
/* fct_right.c */
int		fct_right(t_data *);
/* fct_left.c */
int		fct_left(t_data *);

/* **************** MYLIB ****************** */

int		count_size_line_file(int, int);

void		my_putchar(char, int);

void		my_putstr(char *, int);

void		my_put_nbr(int, int);

int		my_getnbr(char *);

int		my_strlen(char *);

void		my_show_env(char **, int);
void		my_show_tab(char **);

int		count_tab(char **);

char		*my_strcpy_equal(char *);
char		*my_strcpy_full(char *, char *);
char		*my_strcpy_empty(char *);
char		*my_strcpy(char *);
char		*my_cpy(char *, char *);

char            *get_next_line();
char		*mallc_line(char *);

char		*my_epur_str(char *);

int		my_strcmp_equal(char *, char *);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);

void		my_free_cond(t_data *);
void		*my_free_tab(char **);
int		my_free_loop(t_data *);
void		*my_free(void *);

void		*my_mallok(void *, int);

int		check_flags(char, char *);
int		count_words(char *, char *);
char		**my_str_to_wordtab(char *, char *);

int		check_cond(char, char, char *);
char		**my_cond_to_wordtab(char *, char *, int);
int             count_words_cond(char *);

char		*my_strcat(char *, char *, char);

#endif /* SH42_H_ */
