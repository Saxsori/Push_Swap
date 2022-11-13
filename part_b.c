/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:25:12 by aaljaber          #+#    #+#             */
/*   Updated: 2022/02/03 13:02:41 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	scan_bottomf_a(t_stack *st)
{
	int	i;

	i = 0;
	while (st->stack_a[i] != st->mark_bottom)
		i++;
	return (i - 1);
}

void	check_push_to_a(t_stack *st)
{
	if (st->stack_a[0] == st->mark_bottom)
	{
		if (st->stack_a[st->top_a] > st->stack_b[st->top_b])
			push_a(st);
		else if (st->stack_a[st->top_a] < st->stack_b[st->top_b])
			do_ra(st);
	}
	else if (st->stack_a[0] != st->mark_bottom)
	{
		if (st->stack_a[st->top_a] < st->stack_b[st->top_b])
			do_ra(st);
		else if (st->stack_a[st->top_a] > st->stack_b[st->top_b])
		{
			if (st->stack_b[st->top_b] > st->stack_a[0])
				push_a(st);
			else if (st->stack_b[st->top_b] < st->stack_a[0])
				do_rra(st);
		}
	}
}

void	part_b(t_stack *st)
{
	int	i;
	int	uu;

	st->mark_bottom = st->stack_a[0];
	check_push_to_a2(st);
	uu = scan_bottomf_a(st);
	i = -1;
	while (++i <= uu)
		revrot_a(st);
}
