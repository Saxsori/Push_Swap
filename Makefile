# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 12:58:59 by aaljaber          #+#    #+#              #
#    Updated: 2022/02/03 12:59:16 by aaljaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./mang_stack.c ./error_free.c ./push_swap.c ./rot.c ./rev.c ./main.c ./sort_three_two.c ./sort_yourself.c ./sort_five_four.c ./mang_median.c ./check_yourself.c ./apply_small_algo_a.c ./part_a.c ./part_b.c ./part_b2.c ./part_a_utils.c ./part_b_utils.c ./part_b2_utils.c ./apply_small_algo_a_utils.c ./sort_five_four_utils.c

OBJ = ${SRC:.c=.o}

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror -g3

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
		cp ./push_swap ./push_swap_tester/push_swap
		rm ./push_swap_tester/push_swap
		cp ./push_swap ./push_swap_tester/push_swap

.PHONY : all clean fclean re
