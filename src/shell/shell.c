/*
** shell.c for shell in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Tue Apr 26 13:36:04 2016 Thomas CHABOT
<<<<<<< HEAD
** Last update Tue May 31 17:05:34 2016 Thomas LE MOULLEC
*/

#include "42sh.h"

int		pipe_loop(t_data *data)
{
  int		i;

  i = 0;
  while (data->parser.tab_pipe[i] != NULL)
    {
      if (var_env(data, i) == ERROR)
	return (STOP);
      pipe_alias(data, i);
      data->parser.check_pos_pipe = data->parser.nb_pipe[i];
      if (make_pipe(data) == ERROR)
	return (STOP);
      data->parser.tab_pipe[i] = my_epur_str(data->parser.tab_pipe[i]);
      if (data->parser.tab_pipe[i] == NULL)
	return (STOP);
      data->parser.tab_args = my_str_to_wordtab\
	(data->parser.tab_pipe[i], " \t");
      if (args_convert(data) == STOP)
	return (STOP);
      if (my_glob(data) == ERROR || my_exec(data) == ERROR)
	return (STOP);
      my_free_tab(data->parser.tab_args);
      i++;
    }
  return (SUCCESS);
}

int		cond_loop(t_data *data)
{
  int		i;
  int		a;
  int		stop_loop;

  i = 0;
  stop_loop = SUCCESS;
  while (data->parser.tab_cond[i] != NULL && stop_loop != ERROR)
    {
      data->shell.fd_db = 0;
      a = parser_redir(data, i);
      if (a == SUCCESS)
	{
	  data->parser.tab_pipe = my_str_to_wordtab \
	    (data->parser.tab_cond[i], "|");
	  if (take_nb_pipe(data) == ERROR)
	    return (STOP);
	  pipe_loop(data);
	}
      if (data->shell.exit_status != 0 && data->shell.cond[i] == AND)
	while (data->shell.cond[i] == AND)
	  i++;
      if (data->shell.exit_status == 0 && data->shell.cond[i] == OR)
	while (data->shell.cond[i] == OR)
	  i++;
      my_free_cond(data);
      i++;
    }
  return (SUCCESS);
}

int		sep_loop(t_data *data)
{
  int		i;

  i = 0;
  while (data->parser.tab_sep[i] != NULL)
    {
      if ((data->parser.tab_cond = my_cond_to_wordtab	\
	   (data->parser.tab_sep[i], "&|")) == NULL)
	return (my_put_error("Invalid null command.\n", 1));
      if (data->parser.tab_cond != NULL)
	{
	  take_type_cond(data, i, 0, 0);
	  if (cond_loop(data) == ERROR)
	    return (ERROR);
	}
      my_free_tab(data->parser.tab_cond);
      i++;
    }
  return (SUCCESS);
}

int		my_shell(t_data *data)
{
  data->alias = NULL;
  data->alias = add_elem_alias(data->alias, "ls -l", "ll");
  disp_prompt(data);
  data->hist = NULL;
  data->shell.exit_status = 0;
  while ((data->shell.line = get_next_line(0)) != NULL)
    {
      data->hist = add_elem_key(data->hist, data->shell.line);
      if ((magic_quotes(data)) == ERROR)
	return (ERROR);
      if (inhib(data) != ERROR)
	{
	  if (parser_sep(data) != STOP)
	    {
	      sep_loop(data);
	      my_free_loop(data);
	    }
	}
      disp_prompt(data);
    }
  my_putstr("exit\n", 1);
  return (SUCCESS);
}
