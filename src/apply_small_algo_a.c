/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_small_algo_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:34:31 by aaljaber          #+#    #+#             */
/*   Updated: 2023/03/25 01:47:30 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*if(st->stack_a[st->top_a - 1] < st->stack_a[0])
if(st->stack_a[st->top_a] < st->stack_a[0])
Already sorted*/

static void	findd_push(t_stack *st)
{
	st->count_pa = 0;
	st->g = st->top_a + 1;
	apply_ra(st);
	apply_rra(st);
}

static void	first_push(t_stack *st)
{
	if (st->stack_b[st->top_b] > st->stack_a[st->top_a] \
			&& st->stack_b[st->top_b] < st->stack_a[st->top_a - 1])
	{
		push_a(st);
		swap_a(st);
	}
	if (st->stack_b[st->top_b] > st->stack_a[st->top_a - 1] \
			&& st->stack_b[st->top_b] < st->stack_a[0])
	{
		revrot_a(st);
		push_a(st);
		rot_a(st);
		rot_a(st);
	}
	if (st->stack_b[st->top_b] > st->stack_a[0])
	{
		push_a(st);
		rot_a(st);
	}
}

static void	second_push(t_stack *st)
{
	if (st->stack_b[st->top_b] < st->stack_a[st->top_a])
		push_a(st);
	if (st->stack_b[st->top_b] > st->stack_a[st->top_a] \
			&& st->stack_b[st->top_b] < st->stack_a[st->top_a - 1])
	{
		push_a(st);
		swap_a(st);
	}
	if (st->stack_b[st->top_b] > st->stack_a[st->top_a - 2] \
			&& st->stack_b[st->top_b] < st->stack_a[st->top_a - 3])
	{
		revrot_a(st);
		push_a(st);
		rot_a(st);
		rot_a(st);
	}
}

void	small_algo(t_stack *st)
{
	fix_yourself(st, 1);
	find_median(st);
	if (st->top_a + 1 == 5)
	{
		findd_push(st);
		three_algoo(st);
		if (st->stack_b[st->top_b] < st->stack_b[st->top_b - 1])
			swap_b(st);
		first_push(st);
		second_push(st);
	}
	if (st->top_a + 1 == 4)
	{
		push_b(st);
		three_algoo(st);
		first_push(st);
	}
	free_yourself(st);
}
