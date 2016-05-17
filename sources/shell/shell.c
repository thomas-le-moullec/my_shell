/*
** shell.c for shell in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
xs** Started on  Tue Apr 26 13:36:04 2016 Thomas CHABOT
** Last update Tue May 17 17:50:07 2016 Hervé TCHIKLADZE
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
      data->parser.check_pos_pipe = data->parser.nb_pipe[i];
      if (make_pipe(data) == ERROR)
	return (STOP);
      data->parser.tab_pipe[i] = my_epur_str(data->parser.tab_pipe[i]);
      if (data->parser.tab_pipe[i] == NULL)
	return (STOP);
      data->parser.tab_args = my_str_to_wordtab\
	(data->parser.tab_pipe[i], " \t");
      args_convert(data);
      if (my_exec(data) == ERROR)
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
      data->shell.status = SUCCESS;
      a = parser_redir(data, i);
      if (a != STOP)
	{
	  data->parser.tab_pipe = my_str_to_wordtab \
	    (data->parser.tab_cond[i], "|");
	  take_nb_pipe(data);
	  pipe_loop(data);
	}
      if ((data->shell.status == ERROR && data->shell.cond[i] == AND) || \
	  (data->shell.status == SUCCESS && data->shell.cond[i] == OR))
	stop_loop = ERROR;
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
      data->parser.tab_cond = my_cond_to_wordtab \
	(data->parser.tab_sep[i], "&|", 0);
      take_type_cond(data, i, 0, 0);
      if (cond_loop(data) == ERROR)
	return (ERROR);
      my_free_tab(data->parser.tab_cond);
      i++;
    }
  return (SUCCESS);
}

int		my_shell(t_data *data)
{
  disp_prompt(data);
  data->list = NULL;
  while ((data->shell.line = get_next_line()) != NULL)
    {
      data->list = add_elem(data->list, data->shell.line);
      if (inhib(data) != ERROR)
	{
	  if (parser_sep(data) != STOP)
	    {
	      if (sep_loop(data) == ERROR)
		return (ERROR);
	      my_free_loop(data);
	    }
	}
      disp_prompt(data);
    }
  return (SUCCESS);
}
