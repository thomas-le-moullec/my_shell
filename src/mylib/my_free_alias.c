/*
** my_free_alias.c for my_free_alias in /home/le-dio_l/Modules/Module_Prog_shell/42sh/PSU_2015_42sh
** 
** Made by leo LE DIOURON
** Login   <le-dio_l@epitech.net>
** 
** Started on  Wed May 25 15:31:19 2016 leo LE DIOURON
** Last update Fri Jun  3 20:57:41 2016 Thomas CHABOT
*/

#include "42sh.h"

void	my_free_alias(t_alias *alias)
{
  if (alias != NULL)
    {
      while (alias->prev != NULL)
	{
	  alias = alias->prev;
	  alias->next->cmd = my_free(alias->next->cmd);
	  alias->next->name = my_free(alias->next->name);
	  alias->next = my_free(alias->next);
	}
      alias->cmd = my_free(alias->cmd);
      alias->name = my_free(alias->name);
      alias = my_free(alias);
    }
}

void	my_free_hist(t_hist *hist)
{
  if (hist != NULL)
    {
      while (hist->prev != NULL)
	{
	  hist = hist->prev;
	  hist->next->str = my_free(hist->next->str);
	  hist->next = my_free(hist->next);
	}
      hist->str = my_free(hist->str);
      hist = my_free(hist);
    }
}

void	my_free_shell(t_shell *shell)
{
  shell->line = my_free(shell->line);
  shell->tmp_magic = my_free(shell->tmp_magic);
  shell->tmp_hist = my_free(shell->tmp_hist);
  shell->pwd = my_free(shell->pwd);
  shell->oldpwd = my_free(shell->oldpwd);
  shell->home = my_free(shell->home);
  shell->env = my_free_tab(shell->env);
  shell->path = my_free_tab(shell->path);
  shell->cond = my_free(shell->cond);
}

void	my_free_parser(t_parser *parser)
{
  my_free_tab(parser->tab_args);
  parser->infile = my_free(parser->infile);
  parser->outfile = my_free(parser->outfile);
  parser->tab_pipe = my_free_tab(parser->tab_pipe);
  parser->tab_cond = my_free_tab(parser->tab_cond);
  parser->nb_pipe = my_free(parser->nb_pipe);
  my_free_tab(parser->tab_sep);
}

void	my_free_local(t_local *local)
{
  if (local != NULL)
    {
      while (local->prev != NULL)
	{
	  local = local->prev;
	  local->next->cmd = my_free(local->next->cmd);
	  local->next->name = my_free(local->next->name);
	  local->next = my_free(local->next);
	}
      local->cmd = my_free(local->cmd);
      local->name = my_free(local->name);
      local = my_free(local);
    }
}
