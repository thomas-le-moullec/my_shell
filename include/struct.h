/*
** struct.h for struct in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 09:36:23 2016 Thomas CHABOT
** Last update Sun Jun  5 11:19:09 2016 leo LE DIOURON
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct	       	s_data t_data;

typedef struct          s_get
{
  int                   j;
  int                   i;
  int                   a;
  char                  *stock;
  int                   cmpt;
}                       t_get;

typedef struct		s_parser
{
  char			**tab_sep;
  char			**tab_cond;
  char			**tab_pipe;
  char			**tab_args;
  char			*infile;
  char			*outfile;
  int			db_in;
  int			db_out;
  int			check_pos_pipe;
  int			*nb_pipe;
  int			quote;
}			t_parser;

typedef struct		s_shell
{
  int			alias_loop;
  int			chk_magic;
  int			bin;
  char			*line;
  char			*tmp_magic;
  char			*tmp_hist;
  int			pos_list;
  char			**env;
  char			*pwd;
  char			*oldpwd;
  char			*home;
  char			**path;
  int			built;
  int			fd[2];
  int			fd_db;
  int			save_fd;
  int			exit_status;
  int			*cond;
  int			nb_repeat;
  char			*tab_builtins[15];
}			t_shell;

typedef struct		s_hist
{
  struct s_hist		*next;
  struct s_hist		*prev;
  char			*str;
  int			pos;
  int			hour;
  int			min;
}			t_hist;

typedef struct		s_alias
{
  int			flag;
  char			*name;
  char			*cmd;
  struct s_alias	*prev;
  struct s_alias	*next;
}			t_alias;

typedef struct		s_local
{
  char			*name;
  char			*cmd;
  struct s_local        *prev;
  struct s_local        *next;
}			t_local;

typedef struct		s_key
{
  char			*key;
  int			(*function)(t_data *, int *);
}			t_key;

typedef struct		s_period
{
  int			cycle;
  int			init;
  int			cmpt;
}			t_period;

struct		       	s_data
{
  t_key			tab_key[15];
  t_hist		*hist;
  t_shell		shell;
  t_parser		parser;
  t_alias		*alias;
  t_local		*local;
  t_period		period;
};

typedef struct		s_buil
{
  char			*name;
  int			(*function)(t_data *data);
}			t_buil;

typedef struct		s_signal
{
  int			status;
  char			*msg;
}			t_signal;

#endif /* STRUCT_H_ */
