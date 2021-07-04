SRC		= main.c

OBJ		= ${SRC:.c=.o}

NAME	= checker

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

RM 		= rm -f

%.o:		%.c
			${CC} ${CFLAGS} -o $@ -c $< 

all:		${NAME}

${NAME}:	${OBJ}
			${CC} ${CFLAGS} -o $@ $< ../libpush_swap.a ../../libft/libft.a

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all