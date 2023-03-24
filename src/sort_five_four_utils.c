/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_four_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:18:49 by aaljaber          #+#    #+#             */
/*   Updated: 2023/03/25 01:47:30 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	apply_ra(t_stack *st)
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

void	apply_rra(t_stack *st)
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

void	find_push(t_stack *st)
{
	st->count_pa = 0;
	st->g = st->top_a + 1;
	apply_ra(st);
	apply_rra(st);
}
