/*
** struct.h for struct in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 09:36:23 2016 Thomas CHABOT
** Last update Tue Apr 26 18:38:24 2016 leo LE DIOURON
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#define STOP		-2
#define	ERROR		-1
#define SUCCESS		0

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
}			t_parser;

typedef struct		s_shell
{
  char			*line;
  char			**env;
  char			*pwd;
  char			*oldpwd;
  char			*home;
  int			built;
}			t_shell;

typedef struct		s_data
{
  t_shell		shell;
  t_parser		parser;
}			t_data;

typedef struct		s_buil
{
  char			*str;
  int			(*function)(t_data *data);
}			t_buil;

#ENDIF /* STRUCT_H_ */
