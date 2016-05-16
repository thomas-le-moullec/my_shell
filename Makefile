##
## Makefile for Makefile in /home/chabot_t/rendu/PSU/PSU_2015_42sh
## 
## Made by Thomas CHABOT
## Login   <chabot_t@epitech.net>
## 
## Started on  Tue Apr 26 13:18:48 2016 Thomas CHABOT
## Last update Mon May 16 13:10:43 2016 leo LE DIOURON
##

NAME            =       42sh

DEBUG		=	yes

DETAILS		=	no

INC             =       -I includes/

CC              =       gcc

RM              =       rm -rf

CFLAGS          +=       -W -Wall -Werror -Wextra -lncurses
CFLAGS          +=       $(INC)

ifeq ($(DEBUG),yes)
	CFLAGS	+=	-g
endif

MAIN            =       ./sources/main/main.c

MY_SHELL        =       ./sources/shell/shell.c 			\
			./sources/shell/get_env.c 			\
			./sources/shell/init.c 				\


MYLIB           =	./sources/mylib/my_putchar.c           	 	\
                        ./sources/mylib/my_strlen.c		        \
                        ./sources/mylib/my_getnbr.c             	\
			./sources/mylib/my_put_nbr.c            	\
			./sources/mylib/my_putstr.c             	\
			./sources/mylib/count_tab.c             	\
			./sources/mylib/my_show_tab.c           	\
			./sources/mylib/get_next_line.c         	\
			./sources/mylib/my_strcmp.c             	\
			./sources/mylib/my_free.c               	\
			./sources/mylib/my_mallok.c            		\
			./sources/mylib/my_epur_str.c           	\
			./sources/mylib/my_str_to_wordtab.c     	\
			./sources/mylib/my_cond_to_wordtab.c    	\
			./sources/mylib/my_strcat.c             	\
			./sources/mylib/my_strcpy.c             	\

ERROR		=	./sources/error/missing_name.c          	\
			./sources/error/ambiguous.c			\

PARSER		=	./sources/parser/parser.c 			\
			./sources/parser/take_redir.c	 		\
			./sources/parser/parser_redir.c 		\
			./sources/parser/check_redir.c 			\
			./sources/parser/epur_redir.c 			\
			./sources/parser/take_nb_pipe.c 		\
			./sources/parser/take_type_cond.c 		\


DISP		=	./sources/disp/prompt.c				\

BUILTINS	=	./sources/builtins/my_exit.c			\
			./sources/builtins/my_env.c			\
			./sources/builtins/my_unsetenv.c		\
			./sources/builtins/fill_env.c			\
			./sources/builtins/my_setenv.c			\
			./sources/builtins/my_cd.c			\

EXEC		=	./sources/exec/exec.c	                  	\
			./sources/exec/in_and_out.c             	\
			./sources/exec/execution.c              	\
			./sources/exec/my_builtins.c            	\
			./sources/exec/redirection_outfile.c    	\
			./sources/exec/redirection_infile.c     	\
			./sources/exec/make_pipe.c              	\

SRCS            =	$(MAIN)						\
			$(MY_SHELL)					\
			$(MYLIB)					\
			$(ERROR)					\
			$(PARSER)					\
			$(DISP)						\
			$(BUILTINS)					\
			$(EXEC)						\

OBJS            =       $(SRCS:src/%.c=$(OBJSDIR)/%.o)

OBJSDIR		=	objs

all             :       $(NAME)

$(NAME)         :       $(OBJS)
ifeq	($(DETAILS),yes)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
else
	@echo "Compilation ..."
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
endif
ifeq	($(DEBUG),yes)
	@echo "Compiled in DEBUG mode."
endif

$(OBJSDIR)/%.o	:	src/%.c
			@mkdir -p $(dir $@)
ifeq	($(DETAILS),yes)
		$(CC) $(CFLAGS) -c $< -o $@
else
	@echo "Compiled :\t$<"
	@$(CC) $(CFLAGS) -c $< -o $@
endif

clean           :
			@echo "Cleaning object files ..."
			@$(RM) $(OBJS)
			@$(RM) -r $(OBJSDIR)
			@echo "Object files cleaned."

fclean          :       clean
			@echo "Cleaning files ..."
			@$(RM) $(NAME)
			@echo "Files cleaned."

re              :       fclean all
