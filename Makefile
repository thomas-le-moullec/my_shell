##
## Makefile for Makefile in /home/payrau_a/rendu/aProjets/PSU/PSU_2015_42sh
## 
## Made by steeve payraudeau
## Login   <payrau_a@epitech.net>
## 
## Started on  Tue May 24 16:10:08 2016 steeve payraudeau
## Last update Tue May 24 16:12:28 2016 Thomas CHABOT
##

DETAILS		=		no

CC		=		gcc

NAME		=		42sh

CFLAGS		+=		-Wall -W -Werror -Wextra -lncurses
CFLAGS		+=		-I include/

ifeq ($(DEBUG),yes)
	CFLAGS	+= -g
endif

MAIN		=		src/main/main.c					\

MY_SHELL	=		src/shell/shell.c				\
				src/shell/get_env.c				\
				src/shell/init.c				\
				src/shell/katch_signal.c			\

PARSER		=		src/parser/parser.c				\
				src/parser/take_redir.c				\
				src/parser/check_redir.c			\
				src/parser/parser_redir.c			\
				src/parser/epur_redir.c				\
				src/parser/take_nb_pipe.c			\
				src/parser/take_type_cond.c			\

DISP		=		src/disp/prompt.c				\


BUILTINS	=		src/builtins/my_exit.c				\
				src/builtins/my_env.c				\
				src/builtins/my_unsetenv.c			\
				src/builtins/fill_env.c				\
				src/builtins/my_setenv.c			\
				src/builtins/my_cd.c				\
				src/builtins/unalias.c				\
				src/builtins/new_alias.c			\
				src/builtins/echo.c				\


EXEC		=		src/exec/exec.c					\
				src/exec/in_and_out.c				\
				src/exec/execution.c				\
				src/exec/my_builtins.c				\
				src/exec/redirection_outfile.c			\
				src/exec/redirection_infile.c			\
				src/exec/make_pipe.c				\
				src/exec/check_all_access.c			\
				src/exec/signal.c				\

ERROR		=		src/error/ambiguous.c				\
				src/error/error_builtins.c			\
				src/error/error_quote.c				\
				src/error/error_dir.c				\

OPT		=		src/options/var_env.c				\
				src/options/inhib.c				\
				src/options/history.c				\
				src/options/mode_canon.c			\
				src/options/alias.c				\
				src/options/change_alias.c			\

OPT_KEY		=		src/options/fct_clavier/fct_up.c		\
				src/options/fct_clavier/fct_down.c		\
				src/options/fct_clavier/fct_right.c		\
				src/options/fct_clavier/fct_left.c		\

MY_LIB		=		src/mylib/my_putstr.c				\
				src/mylib/my_putchar.c				\
				src/mylib/my_strlen.c				\
				src/mylib/my_getnbr.c				\
				src/mylib/my_put_nbr.c				\
				src/mylib/count_tab.c				\
				src/mylib/my_show_tab.c				\
				src/mylib/get_next_line.c			\
				src/mylib/my_strcmp.c				\
				src/mylib/my_free.c				\
				src/mylib/my_mallok.c				\
				src/mylib/my_epur_str.c				\
				src/mylib/my_str_to_wordtab.c			\
				src/mylib/my_cond_to_wordtab.c			\
				src/mylib/my_strcat.c				\
				src/mylib/count_size_line_file.c		\
				src/mylib/my_strcpy.c				\
				src/mylib/show_alias.c				\
				src/mylib/my_put_error.c			\
				src/mylib/cut.c					\
				src/mylib/get_dir.c				\


SRC	=			$(MAIN)						\
				$(MY_SHELL)					\
				$(PARSER)					\
				$(DISP)						\
				$(BUILTINS)					\
				$(EXEC)						\
				$(ERROR)					\
				$(OPT)						\
				$(OPT_KEY)					\
				$(MY_LIB)					\

OBJ	=			$(SRC:src/%.c=$(OBJDIR)/%.o)

OBJDIR	=			obj

all:		$(NAME)

$(NAME):	$(OBJ)
ifeq ($(DETAILS),yes)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
else
	@echo "Compiling executable..."
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
endif
ifeq ($(DEBUG),yes)
	@echo "$(NAME) compiled in debug mode dear $(USER)."
endif

$(OBJDIR)/%.o:	src/%.c
	@mkdir -p $(dir $@)
ifeq ($(DETAILS),yes)
	$(CC) $(CFLAGS) -c $< -o $@
else
	@echo -e "Compile:\t$<"
	@$(CC) $(CFLAGS) -c $< -o $@
endif

clean:
	@echo "Cleaning object files ..."
	@$(RM) $(OBJS)
	@$(RM) -r $(OBJDIR)
	@echo "Object files cleaned."

fclean:	clean
	@echo "Cleaning files ..."
	@$(RM) $(NAME)
	@echo "Files cleaned."

re:	fclean all

