SRCS	= main.c

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

%.o:		%.c ../libpush_swap.a ../../libft/libft.a
			${CC} ${CFLAGS} -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o $@ $< ../libpush_swap.a ../../libft/libft.a

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all