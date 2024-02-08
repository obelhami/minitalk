SRCS			= client.c server.c \

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME = minitalk.a

all : $(NAME)
$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
re:		fclean $(NAME)