/*
** 42sh.h for 42sh in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue May 24 09:39:01 2016 Thomas CHABOT
** Last update Sat Jun  4 17:17:02 2016 Thomas LE MOULLEC
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
#include <time.h>
#include "struct.h"
#include "define.h"

void            end_fct(t_data *);
int		pipe_loop(t_data *, int);
int		cond_loop(t_data *, int);
int		sep_loop(t_data *);
int		my_shell(t_data *);
int		parser_line(t_data *);
int             my_shell_key(t_data *);
int	        catch_key(t_data *);
int		get_env(t_data *, char **);
int		get_path(t_data *);
int		get_home(t_data *);
int		get_old_pwd(t_data *);
int		get_pwd(t_data *);
int		init_shell(t_data *);
void    	*my_handler(int);
void		init_signaux();
int             modify_str_pipe(t_data *, int);
int             modify_inhib_glob_pipe(t_data *);
void		pipe_alias(t_data *, int);
int		gestion_condition(t_data *, int);
int             exec_without_path_fork(t_data *);
int		exec_without_path(t_data *);
int		check_str_access(char *);
int		my_exec(t_data *);
void		init_tab_builtins(t_data *);
int		show_builtins(t_data *);
int		my_builtins(t_data *, int);
int		father(pid_t, t_data *);
int		execution(t_data *);
int		exec_with_path(t_data *, int);
int		err_redir_outfile(t_data *, int);
int		err_db_redir_outfile(t_data *, int);
int		redirection_outfile(t_data *);
int		redirection_infile(t_data *);
int             double_infile_redir(t_data *);
int             infile_simple(t_data *);
int		manage_all_redir(t_data *);
int		manage_pipe(t_data *);
int		in_and_out(t_data *);
int		make_pipe(t_data *);
char		*take_path_exec(char *);
int		check_signal(t_data *, int);
int		access_path_er(t_data *);
int		access_path_file(t_data *);
int             find_path_exec(t_data *);
int		access_path(t_data *);
char		*check_cd(t_data *);
int		my_cd(t_data *);
int		my_env(t_data *);
int		check_env_exist(t_data *, char *);
int		setenv_empty(t_data *, int);
int		my_setenv(t_data *);
int		check_alpha(char *);
char		**fill_env_none(t_data *, char **, int);
char		**fill_env_loop(t_data *, int, char **, int);
char		**fill_env(t_data *, int);
int		my_exit(t_data *);
char		**unsetenv_loop(t_data *, int);
int		my_unsetenv(t_data *);
void            delete_existant_alias(t_data *);
int		new_alias(t_data *);
int		delete_alias(t_data *);
int		unalias(t_data *);
int		my_echo(t_data *);
int		my_history(t_data *);
void            delete_existant_local(t_data *, char *);
int             delete_local(t_data *);
int		my_unset(t_data *);
void		show_set(t_data *);
t_local         *add_elem_local(t_local *, char *, char *);
char            *take_cmd_local(char *);
char            *take_name_local(char *);
int		my_set(t_data *);
int		my_repeat(t_data *);
int		check_where(char *);
int		my_where_loop(t_data *, int, char *, int);
int		is_builtin(t_data *, char *);
int		my_where(t_data *);
char		*cut_str(char *);
int		check_which(t_data *, char *, int, int);
char		*get_which(char *);
int		my_which_check(t_data *, char *, int, int);
void		my_which_loop(t_data *, char *, int, int);
int		my_which(t_data *);
int	        parser_cond(t_data *);
int		parser_sep(t_data *);
int		take_outfile(char *, int, t_data *);
int		take_infile(char *, int, t_data *);
int		manage_outfile(t_data *, int, int *);
int		manage_infile(t_data *, int, int *);
int		check_redir_in(t_data *, char *);
int		check_redir_out(t_data *, char *);
int		parser_redir(t_data *, int);
char		*epur_redir(char *, int);
int		take_nb_pipe(t_data *);
void		take_type_cond(t_data *, int, int, int);
int		ambiguous(t_data *, int);
int		not_found_cmd(t_data *, char *, int);
int		error_denied(t_data *, char *);
void		error_no_file(t_data *, char *);
int		error_alpha(t_data *, int);
int		error_event(t_data *, char *);
void            *error_quote(t_data *, char);
int             error_not_found(t_data *);
int             error_dir(t_data *, char *);
int             error_perm(t_data *);
int             glob_error(const char *, int);
void		bin_not_comp(t_data *);
void		disp_prompt(t_data *);
int             modif_args_hist(t_data *, int);
int             modif_args_hist_check(t_data *, int, char *);
char            *strcop_char(char **, char);
char            *cp_str(char *, char *, int);
int		var_env_loc(t_data *, int);
int		replace_string(t_data *, int, int, char *);
char		*take_var(t_data *, int, int);
void            creat_new_string(t_data *, char *, int);
int             inhib(t_data *);
char            *modify_str(t_data *, char, int);
int             check_special_char(char, char *);
int             args_convert(t_data *);
int             get_nb_cmd(t_data *, char *, int);
int             get_relative_cmd(t_data *, char *, int);
int             check_n_hist(t_data *, char *, int);
char            *change_line_hist(t_data *, char *, int);
char            *take_tmp_hist(t_data *, int, int, int);
t_hist		*add_elem_key(t_hist *, char *);
t_hist		*get_time(t_hist *);
void		print_hist_date(t_data *);
int		print_hist(t_data *);
int		mode_canon(int);
int             init_tab_ctrl(t_data *);
int		init_tab(t_data *);
int		init_term(t_data *);
t_alias         *add_elem_alias(t_alias *, char *, char *);
int             check_alias_in(t_data *, int, int *);
void            modify_string_alias(t_data *, int, int, int);
int             find_valid_alias(t_data *, int, int *);
void            change_alias_loop(t_data *, int, int *, int);
int             change_alias(t_data *, int);
int             my_glob(t_data *);
char            **replace_stars(t_data *, int *);
char            **take_tab_stars(char *, char *, t_data *);
int             glob_error(const char *, int);
int             check_stars(char *);
char            **my_magic_wordtab(char *, int, int);
char            *epur_return_line(char *);
int             modify_magic_line(t_data *);
int             magic_quotes(t_data *);
int             exe_magic_quotes(t_data *, char **, int, int);
int             loop_magic(t_data *, char **);
char            *change_magic_result(char *, char *);
char            *fill_result_magic(char *, char *, char *);
void		precmd(t_data);
void		postcmd(t_data);
int		periodic(t_data *);
int		get_time_period();
int		fct_up(t_data *, int *);
int		fct_down(t_data *, int *);
void            clear_print_line(char *, int *, int);
int		fct_right(t_data *, int *);
int		fct_left(t_data *, int *);
int		fct_tab(t_data *, int *);
int		fct_delete(t_data *, int *);
int		fct_supp(t_data *, int *);
int		fct_reset(t_data *, int *);
int		fct_end(t_data *, int *);
int		fct_kome(t_data *, int *);
int		fct_clear(t_data *, int *);
int		fct_eof(t_data *, int *);
char		*my_char(char);
int             found_tabo_comp(char **, char *);
int             reinit_cursor(t_data *, int);
void            found_positions(char *, int, int *, int *);
int             print_autocompletion(t_data *, char *, int *);
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
void		my_free_local(t_local *);
void		my_free_hist(t_hist *);
void		my_free_shell(t_shell *);
void		my_free_parser(t_parser *);
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
int             count_occurrence(char *, char);
char		*check_in_alias(t_data *, char *);
char		*check_in_set(t_data *, char *);

#endif /* SH42_H_ */
