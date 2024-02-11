# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelhami <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 20:00:11 by obelhami          #+#    #+#              #
#    Updated: 2024/02/11 20:00:14 by obelhami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= client.c server.c \

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME = server client

all : $(NAME)
bonus: server_bonus client_bonus

$(NAME): client.c server.c
		$(CC) $(CFLAGS) client.c ft_itoa.c ft_atoi.c -o client
		$(CC) $(CFLAGS) server.c ft_putnbr.c -o server

server_bonus: server_bonus.c
	$(CC) $(CFLAGS) server_bonus.c ft_putnbr.c -o server_bonus

client_bonus: client_bonus.c
	$(CC) $(CFLAGS) client_bonus.c ft_atoi.c ft_itoa.c -o client_bonus

clean:
	$(RM) $(NAME)

fclean:
		$(RM) $(NAME)
		$(RM) server_bonus client_bonus

re:		fclean $(NAME)
