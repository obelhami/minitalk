SRCS			= client.c server.c \

# OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME = server client

all : $(NAME)
$(NAME): client.c server.c
		$(CC) $(CFLAGS) client.c -o client
		$(CC) $(CFLAGS) server.c -o server
		
clean:
			$(RM) $(NAME)

fclean: clean
		$(RM) $(NAME)
re:		fclean $(NAME)