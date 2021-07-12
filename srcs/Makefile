SRCS	= silent/chunk_sort_bside_plus_silent.c\
		  silent/chunk_sort_bside_silent.c\
		  silent/chunk_sort_plus_silent.c\
		  silent/chunk_sort_silent.c\
		  silent/operations_silent.c\
		  silent/silent_utils.c\
		  sort/chunk_sort_bside_plus.c\
		  sort/chunk_sort_bside.c\
		  sort/chunk_sort_plus.c\
		  sort/chunk_sort.c\
		  sort/sort_utils.c\
		  sort/sort_utils2.c\
		  sort/three_and_five_sort.c\
		  operations.c\
		  parsing.c\
		  push_swap_utils.c\
		  checker_utils.c  

OBJS	= ${SRCS:.c=.o}

NAME	= libpush_swap.a

CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

%.o:		%.c
			${CC} ${CFLAGS} -o $@ -c $< 

all:		${NAME}

${NAME}:	${OBJS}
			ar r ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}
		
fclean:		clean
			${RM} ${NAME}

re:			fclean all