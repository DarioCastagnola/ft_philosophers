# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 14:52:32 by dcastagn          #+#    #+#              #
#    Updated: 2023/04/28 09:55:30 by dcastagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
PHILO = main.c utils1.c init_data.c checks.c
OBJ = ${PHILO:.c=.o}
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

.o:.c
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}:
	${CC} ${FLAGS} ${PHILO} -o ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all
