# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 16:55:24 by mle-duc           #+#    #+#              #
#    Updated: 2023/11/29 02:32:36 by mle-duc          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			parsing

CC =			cc

RM =			rm -f

INC_DIR =		./includes

LIBFT_DIR =		./libft

SRCS =			$(addprefix src/, \
				main.c parsing.c utils.c utils2.c map_checker.c)

OBJS =			${SRCS:.c=.o}

CFLAGS =		-g3

LIBFT_PATH =	libft/libft.a

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -I $(INC_DIR) -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C libft
	@$(CC) $(OBJS) ${CFLAGS} -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	${RM} ${OBJS}
	make clean -C libft

fclean: clean
	${RM} ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
