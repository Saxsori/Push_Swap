/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_small_algo_a_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:59:57 by aaljaber          #+#    #+#             */
/*   Updated: 2023/03/25 01:47:30 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	doo_ra(t_stack *st)
{
	while (--st->g > 2 && st->count_pa != 2)
	{
		if (st->stack_a[st->g] > st->median || st->stack_a[st->g] < st->median)
		{
			if (st->g == st->top_a)
				push_b(st);
			else
			{
				rot_a(st);
				push_b(st);
			}
			st->count_pa++;
		}
	}
}

void	doo_rra(t_stack *st)
{
	while (--st->g > -1 && st->count_pa != 2)
	{
		if (st->stack_a[st->g] > st->median || st->stack_a[st->g] < st->median)
		{
			if (st->g == 0)
			{
				swap_a(st);
				push_b(st);
			}
			else
			{
				rot_a(st);
				push_b(st);
			}
			st->count_pa++;
		}
	}
}

static void	small_topcheck(t_stack *st)
{
	if (st->stack_a[st->top_a - 1] > st->stack_a[0])
	{
		if (st->stack_a[st->top_a] < st->stack_a[0])
		{
			revrot_a(st);
			swap_a(st);
		}
		if (st->stack_a[st->top_a] > st->stack_a[0])
			revrot_a(st);
	}
}

static void	big_topcheck(t_stack *st)
{
	if (st->stack_a[st->top_a - 1] < st->stack_a[0])
	{
		if (st->stack_a[st->top_a] < st->stack_a[0])
			swap_a(st);
		else if (st->stack_a[st->top_a] > st->stack_a[0])
			rot_a(st);
	}
	else if (st->stack_a[st->top_a - 1] > st->stack_a[0])
	{
		swap_a(st);
		revrot_a(st);
	}
}

void	three_algoo(t_stack *st)
{
	if (st->stack_a[st->top_a] < st->stack_a[st->top_a - 1])
		small_topcheck(st);
	else if (st->stack_a[st->top_a] > st->stack_a[st->top_a - 1])
		big_topcheck(st);
}
