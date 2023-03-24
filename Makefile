# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 12:58:59 by aaljaber          #+#    #+#              #
#    Updated: 2023/03/25 01:55:04 by aaljaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/mang_stack.c ./src/error_free.c ./src/push_swap.c ./src/rot.c ./src/rev.c ./src/main.c ./src/sort_three_two.c ./src/sort_yourself.c ./src/sort_five_four.c ./src/mang_median.c ./src/check_yourself.c ./src/apply_small_algo_a.c ./src/part_a.c ./src/part_b.c ./src/part_b2.c ./src/part_a_utils.c ./src/part_b_utils.c ./src/part_b2_utils.c ./src/apply_small_algo_a_utils.c ./src/sort_five_four_utils.c

OBJ = ${SRC:.c=.o}

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror -g3

RM = rm -rf

all : ${NAME}

${NAME}: ${OBJ}
		${MAKE} -C ./incl/libft
		${CC} ${FLAGS} ${SRC} ./incl/libft/libft.a -o ${NAME}

clean : 
		${MAKE} fclean -C ./incl/libft
		${RM} ${OBJ}

fclean : clean
		${RM} ${NAME}

re : fclean all
		cp ./push_swap ./Testers/push_swap_tester/push_swap
		rm ./Testers/push_swap_tester/push_swap
		cp ./push_swap ./Testers/push_swap_tester/push_swap

.PHONY : all clean fclean re
