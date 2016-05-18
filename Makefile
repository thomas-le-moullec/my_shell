##
## Makefile for Makefile in /home/chabot_t/rendu/PSU/PSU_2015_42sh
## 
## Made by Thomas CHABOT
## Login   <chabot_t@epitech.net>
## 
## Started on  Tue Apr 26 13:18:48 2016 Thomas CHABOT
## Last update Wed May 18 14:32:11 2016 steeve payraudeau
##

NAME            =       42sh

MAIN            =       ./sources/main/

MY_SHELL        =       ./sources/shell/

MYLIB           =       ./sources/mylib/

ERROR		=	./sources/error/

PARSER		=	./sources/parser/

DISP		=	./sources/disp/

BUILTINS	=	./sources/builtins/

EXEC		=	./sources/exec/

OPT		=	./sources/options/

OPT_KEY		=	./sources/options/fct_clavier/

SRCS            =       $(MAIN)main.c                   \
                        $(MY_SHELL)shell.c              \
                        $(MY_SHELL)get_env.c            \
                        $(MY_SHELL)init.c               \
			$(PARSER)parser.c		\
			$(PARSER)take_redir.c		\
			$(PARSER)parser_redir.c		\
			$(PARSER)check_redir.c		\
			$(PARSER)epur_redir.c		\
			$(PARSER)take_nb_pipe.c		\
			$(PARSER)take_type_cond.c	\
			$(DISP)prompt.c			\
			$(BUILTINS)my_exit.c		\
			$(BUILTINS)my_env.c		\
			$(BUILTINS)my_unsetenv.c	\
			$(BUILTINS)fill_env.c		\
			$(BUILTINS)my_setenv.c		\
			$(BUILTINS)my_cd.c		\
			$(EXEC)exec.c                   \
			$(EXEC)in_and_out.c             \
			$(EXEC)execution.c              \
			$(EXEC)my_builtins.c            \
			$(EXEC)redirection_outfile.c    \
			$(EXEC)redirection_infile.c     \
			$(EXEC)make_pipe.c              \
			$(ERROR)missing_name.c          \
			$(ERROR)ambiguous.c		\
			$(ERROR)error_builtins.c	\
			$(ERROR)error_quote.c		\
			$(OPT)var_env.c			\
			$(OPT)inhib.c			\
			$(OPT)history.c			\
			$(OPT)mode_canon.c		\
			$(OPT_KEY)fct_up.c		\
			$(OPT_KEY)fct_down.c		\
			$(OPT_KEY)fct_right.c		\
			$(OPT_KEY)fct_left.c		\
			$(MYLIB)my_putchar.c            \
                        $(MYLIB)my_strlen.c             \
                        $(MYLIB)my_getnbr.c             \
			$(MYLIB)my_put_nbr.c            \
			$(MYLIB)my_putstr.c             \
			$(MYLIB)count_tab.c             \
			$(MYLIB)my_show_tab.c           \
			$(MYLIB)get_next_line.c         \
			$(MYLIB)my_strcmp.c             \
			$(MYLIB)my_free.c               \
			$(MYLIB)my_mallok.c             \
			$(MYLIB)my_epur_str.c           \
			$(MYLIB)my_str_to_wordtab.c     \
			$(MYLIB)my_cond_to_wordtab.c    \
			$(MYLIB)my_strcat.c             \
			$(MYLIB)my_strcpy.c             \

OBJS            =       $(SRCS:.c=.o)

INC             =       includes/

CC              =       gcc -g

RM              =       rm -rf

CFLAGS          =       -I $(INC) -W -Wall -Werror -Wextra -lncurses

all             :       $(NAME)

$(NAME)         :       $(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean           :
			$(RM) $(OBJS)

fclean          :       clean
			$(RM) $(NAME)

re              :       fclean all

