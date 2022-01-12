SRC = ./mang_stack.c ./error_free.c ./push_swap.c ./rot.c ./rev.c ./check.c ./main.c ./sort_three_two.c ./sort_yourself.c ./sort_five_four.c ./mang_median.c ./check_yourself.c ./apply_small_algo_a.c ./part_a.c ./part_b.c

OBJ = ${SRC:.c=.o}

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

all : ${NAME}

${NAME}: ${OBJ}
		${MAKE} -C ./libft
		${CC} ${FLAGS} ${SRC} ./libft/libft.a -o ${NAME}

clean : 
		${MAKE} fclean -C ./libft
		${RM} ${OBJ}

fclean : clean
		${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re