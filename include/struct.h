/*
** struct.h for struct in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 09:36:23 2016 Thomas CHABOT
** Last update Tue May 24 14:17:47 2016 Thomas CHABOT
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#define STOP		-2
#define	ERROR		-1
#define SUCCESS		0

#define ALONE		0
#define BEGIN		1
#define MIDDLE		2
#define END		3

#define DEFAUT		0
#define AND		1
#define OR		2

#define MAGIC		"108 97 103 111 117 100 97 108 101"

#define NB_SIGNALS	5

#define AMBI_INPUT	"Ambiguous input redirect\n"
#define AMBI_OUTPUT	"Ambiguous output redirect\n"
#define ER_UNSETENV	"unsetenv: Too few arguments.\n"
#define ER_SETENV	"setenv: Too many arguments.\n"
#define NOT_FOUND	": Command not found.\n"
#define NOT_DIR		": Not a directory.\n"
#define PERM_DENIED	": Permissions denied.\n"
#define MISSING_NAME	"Missing name for redirect.\n"

#define SIG_SIGABRT		"Aborted\n"
#define SIG_SIGFPE		"Floating point exception\n"
#define SIG_SIGQUIT		"Quit\n"
#define SIG_SIGSEGV		"Segmentation fault\n"
#define SIG_SIGILL		"Illegal Instruction\n"

typedef struct	       	s_data t_data;

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
}			t_parser;

typedef struct		s_shell
{
  int			bin;
  char			*line;
  char			**env;
  char			*pwd;
  char			*oldpwd;
  char			*home;
  char			**path;
  int			built;
  int			fd[2];
  int			fd_db;
  int			save_fd;
  int			status;
  int			exit_status;
  int			*cond;
}			t_shell;

typedef struct		s_hist
{
  struct s_hist		*next;
  struct s_hist		*prev;
  char			*str;
  int			pos;
}			t_hist;

typedef struct		s_alias
{
  char			*name;
  char			*cmd;
  struct s_alias	*prev;
  struct s_alias	*next;
}			t_alias;

typedef struct		s_key
{
  char			*key;
  int			(*function)(t_data *);
}			t_key;

struct		       	s_data
{
  t_key			tab_key[5];
  t_hist		*list;
  t_shell		shell;
  t_parser		parser;
  t_alias		*alias;
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
