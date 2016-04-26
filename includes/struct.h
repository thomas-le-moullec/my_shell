/*
** struct.h for struct in /home/chabot_t/rendu/PSU/PSU_2015_42sh
** 
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
** 
** Started on  Tue Apr 26 09:36:23 2016 Thomas CHABOT
** Last update Tue Apr 26 13:26:05 2016 Thomas CHABOT
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#define STOP		-2
#define	ERROR		-1
#define SUCCESS		0



typedef struct		s_shell
{
  char			**env;
}			t_shell;

typedef struct		s_data
{
  t_shell		shell;
}			t_data;

#endif /* STRUCT_H_ */
