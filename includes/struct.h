/*
** struct.h for struct in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 09:36:23 2016 Thomas CHABOT
** Last update Wed May 18 18:03:57 2016 steeve payraudeau
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

#endif /* STRUCT_H_ */
