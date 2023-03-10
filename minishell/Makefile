# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 11:39:02 by chabrune          #+#    #+#              #
#    Updated: 2023/03/14 15:41:08 by chabrune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################################
###### ARGUMENTS

NAME    	=       minishell
CFLAGS  	=       -Wextra -Wall -Werror -g3
CC      	=       gcc
RM      	=       rm -rf
LIBFT		=		"libft/libft.a"
READLINE	=		 -lreadline -L readline
OBJS    	=       $(SRCS:.c=.o)

#######################################################
###### SOURCES

SRCS       	=	main.c \
				lexer.c \
				parser/parser1.c \
				parser/parser2.c \
				parser/parser3.c \
				parser/parser_utils.c \
				check_quotes.c \
				get_env.c \
				lst_utils.c \
				builtins/builtins.c \
				executor/exec.c \


#######################################################
###### RULES

.c.o:
			gcc ${CFLAGS} -I readline/include  -c $< -o $(<:.c=.o)

all:		${NAME}

${NAME}:	${OBJS}
			${MAKE} -C libft
			gcc ${CFLAGS} ${OBJS} ${LIBFT} ${READLINE} -o ${NAME}

debug:		fclean ${OBJS}
			${MAKE} -C libft
			gcc ${CFLAGS} -fsanitize=address ${OBJS} ${LIBFT} ${READLINE} -o ${NAME}

clean:
			${RM} ${OBJS}
			${MAKE} -C libft clean

fclean:		clean
			${RM} ${NAME}
			${MAKE} -C libft fclean

re:			fclean all

.PHONY:		all clean re fclean