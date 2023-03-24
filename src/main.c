/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:40:59 by aaljaber          #+#    #+#             */
/*   Updated: 2023/03/25 01:47:30 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	struct_init(t_stack *stack)
{
	stack->top_a = 0;
	stack->ele_tot = 0;
	stack->top_b = 0;
}

void	control_algo(t_stack *st)
{
	if (!is_sort(st) && st->ele_tot > 1)
	{
		if (st->ele_tot != 5 && st->ele_tot != 4)
			free_yourself(st);
		if (st->ele_tot == 2)
			two_algo(st);
		if (st->ele_tot == 3)
			three_algo(st);
		if (st->ele_tot == 5 || st->ele_tot == 4)
			fivfor_algo(st);
		if (st->ele_tot > 5)
			big_algo(st);
	}
	else
	{
		free_stack(st);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	struct_init(&stack);
	if (argc > 1)
	{
		mang_stack(argv, argc, &stack);
		control_algo(&stack);
		free_stack(&stack);
	}
	return (0);
}
