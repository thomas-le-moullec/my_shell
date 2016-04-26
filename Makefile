##
## Makefile for Makefile in /home/chabot_t/rendu/PSU/PSU_2015_42sh
## 
## Made by Thomas CHABOT
## Login   <chabot_t@epitech.net>
## 
## Started on  Tue Apr 26 13:18:48 2016 Thomas CHABOT
## Last update Tue Apr 26 17:37:27 2016 leo LE DIOURON
##

NAME            =       42sh

MAIN            =       ./sources/main/

MY_SHELL        =       ./sources/shell/

MYLIB           =       ./sources/mylib/

ERROR		=	./sources/error/

PARSER		=	./soucres/parser/

DISP		=	./sources/disp/

BUILTINS	=	./sources/builtins/

SRCS            =       $(MAIN)main.c                   \
                        $(MY_SHELL)shell.c              \
                        $(MY_SHELL)get_env.c            \
                        $(MY_SHELL)init.c               \
			$(PARSER)parser.c		\
			$(PARSER)take_redir.c		\
			$(DISP)prompt.c			\
			$(BUILTINS)my_exit.c		\
			$(BUILTINS)my_env.c		\
			$(BUILTINS)my_unsetenv.c	\
			$(BUILTINS)my_setenv.c		\
			$(MYLIB)my_putchar.c            \
                        $(MYLIB)my_strlen.c             \
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

