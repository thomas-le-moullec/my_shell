/*
** shell.c for shell in /home/chabot_t/rendu/PSU/PSU_2015_42sh
**
** Made by Thomas CHABOT
** Login   <chabot_t@epitech.net>
**
** Started on  Tue Apr 26 13:36:04 2016 Thomas CHABOT
** Last update Fri Apr 29 15:18:04 2016 leo LE DIOURON
*/

#include "42sh.h"

int		args_loop(t_data *data)
{
  int		i;

  i = 0;
  while (data->parser.tab_pipe[i] != NULL)
    {
      data->parser.tab_pipe[i] = my_epur_str(data->parser.tab_pipe[i]);
      data->parser.tab_args = my_str_to_wordtab(data->parser.tab_pipe[i], " \t");
      if (my_exec(data) == ERROR)
	return (ERROR);
      my_free_tab(data->parser.tab_args);
      i++;
    }
  return (SUCCESS);
}

int		pipe_loop(t_data *data)
{
  int		i;

  i = 0;
  while (data->parser.tab_cond[i] != NULL)
    {
      if (parser_redir(data, i) == ERROR)
	return (ERROR);
      data->parser.tab_pipe = my_str_to_wordtab(data->parser.tab_cond[i], "|");
      printf("..%s.. et .%s.\n", data->parser.tab_cond[i], data->parser.outfile);
      if (args_loop(data) == ERROR)
	return (ERROR);
      my_free_tab(data->parser.tab_pipe);
      my_free(data->parser.infile);
      my_free(data->parser.outfile);
      i++;
    }
  return (SUCCESS);
}

int		cond_loop(t_data *data)
{
  int		i;

  i = 0;
  while (data->parser.tab_sep[i] != NULL)
    {
      data->parser.tab_cond = my_cond_to_wordtab(data->parser.tab_sep[i], "&|");
      if (pipe_loop(data) == ERROR)
	return (ERROR);
      my_free_tab(data->parser.tab_cond);
      i++;
    }
  return (SUCCESS);
}

int		my_shell(t_data *data)
{
  disp_prompt(data);
  while ((data->shell.line = get_next_line()) != NULL)
    {
      if (parser_sep(data) != STOP)
	{
	  if (cond_loop(data) == ERROR)
	    return (ERROR);
	  my_free_loop(data);
	}
      disp_prompt(data);
    }
  return (SUCCESS);
}
