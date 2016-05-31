/*
** 42sh.h for 42sh in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue May 24 09:39:01 2016 Thomas CHABOT
** Last update Tue May 31 11:30:00 2016 leo LE DIOURON
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
#include <errno.h>
#include <glob.h>
#include "struct.h"

/* **************** SHELL ****************** */

/* main.c */
void            end_fct(t_data *);

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

/* katch_signal.c */
void    	*my_handler(int);
void		init_signaux();

/* pipe_loop.c */
void		pipe_alias(t_data *, int);

/* **************** EXEC ****************** */

/* exec.c */
int		check_str_access(char *);
int		my_exec(t_data *);

/*my_builtins.c */
int		show_builtins(t_data *);
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

/*check_all_access.c*/
char		*take_path_exec(char *);

/* signal.c */
int		check_signal(t_data *, int);

/* check_signal.c */
int		access_path_er(t_data *);
int		access_path_file(t_data *);

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
int		check_alpha(char *);

/* fill_env.c */
char		**fill_env_none(t_data *, char **, int);
char		**fill_env_loop(t_data *, int, char **, int);
char		**fill_env(t_data *, int);

/* my_env.c */
int		my_exit(t_data *);

/* my_unsetenv.c */
char		**unsetenv_loop(t_data *, int);
int		my_unsetenv(t_data *);

/* new_alias.c */
int		new_alias(t_data *);

/* unalias.c */
int		delete_alias(t_data *);
int		unalias(t_data *);

/* echo.c */
int		my_echo(t_data *);

/* my_history.c */
int		my_history(t_data *);

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
int		check_redir_in(t_data *, char *);
int		check_redir_out(t_data *, char *);

/* parser_redir.c */
int		parser_redir(t_data *, int);

/* epur_redir.c */
char		*epur_redir(char *, int);

/* take_nb_pipe.c */
int		take_nb_pipe(t_data *);

/*take_type_cond.c */
void		take_type_cond(t_data *, int, int, int);

/* **************** ERROR ****************** */

/* ambiguous.c */
int		ambiguous(t_data *, int);

/* error_bultins.c */
int		error_denied(t_data *, char *);
void		error_no_file(t_data *, char *);
int		error_alpha(t_data *, int);
int		error_event(t_data *, char *);

/* error_quote.c */
void            *error_quote(t_data *, char);

/* error_dir.c */
int             error_not_found(t_data *);
int             error_dir(t_data *, char *);
int             error_perm(t_data *);

/* error_glob.c */
int             glob_error(const char *, int);

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
int             args_convert(t_data *);

/* history.c */
int             modif_args_hist(t_data *, int);
t_hist		*add_elem_key(t_hist *, char *);
int		print_list(t_data *);

/* mode_canon.c */
int		mode_canon(int);

/* alias.c */
t_alias         *add_elem_alias(t_alias *, char *, char *);


/* change_alias.c */
int             check_alias_in(t_data *, int, int *);
void            modify_string_alias(t_data *, int, int, int);
int             find_valid_alias(t_data *, int, int *);
void            change_alias_loop(t_data *, int, int *, int);
int             change_alias(t_data *, int);

/*     glob.c   */
int             my_glob(t_data *);
char            **replace_stars(t_data *, int *);
char            **take_tab_stars(char *, char *);
int             glob_error(const char *, int);
int             check_stars(char *);

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
char		*my_strcpy(char *);
char		*my_cpy(char *, char *);

char            *get_next_line(int);
char		*mallc_line(char *);

char		*my_epur_str(char *);

int		my_strcmp_equal(char *, char *);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);

void		my_free_cond(t_data *);
void		*my_free_tab(char **);
int		my_free_loop(t_data *);
void		*my_free(void *);

void		my_free_alias(t_alias *);

void		*my_mallok(void *, int);

int		check_flags(char, char *);
int		count_words(char *, char *);
char		**my_str_to_wordtab(char *, char *);

int		check_cond(char, char, char *);
char		**my_cond_to_wordtab_loop(char **, int, char *, char *);
char		**my_cond_to_wordtab(char *, char *);
int             count_words_cond(char *);

char		*my_strcat(char *, char *, char);

char		*cut_extrem(char *);

int		my_put_error(char *, int);

char		*get_dir(char *);

void            show_alias(t_data *);

#endif /* SH42_H_ */
