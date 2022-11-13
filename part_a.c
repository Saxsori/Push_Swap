/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:25:42 by aaljaber          #+#    #+#             */
/*   Updated: 2022/02/02 19:55:18 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_push_to_b(t_stack *st)
{
	int	top;
	int	bottom;
	int	i;

	i = -1;
	top = scan_top_a(st);
	bottom = scan_bottom_a(st);
	if (initial_check_a(st) && \
			(bottom >= top || bottom == top - 1) && st->top_a > 1)
	{
		while (++i <= top && st->stack_a[st->top_a] > st->median)
			rot_a(st);
	}
	else if (initial_check_a(st) && bottom < top && st->top_a > 1)
	{
		i = -1;
		while (++i <= bottom && st->stack_a[st->top_a] > st->median)
			revrot_a(st);
	}
}

int	limit_calc(t_stack *st)
{
	int	limit;

	if (st->ele_tot < 500)
		limit = HUND_CHUNK * HUND_CHUNK;
	if (st->ele_tot > 100)
		limit = FIHUND_CHUNK * FIHUND_CHUNK + 10;
	return (limit);
}

void	algo(t_stack *st)
{
	int	i;

	i = 0;
	while (initial_check_a(st) && i < st->range_size)
	{
		if (st->stack_a[st->top_a] <= st->median)
			push_b(st);
		else
		{
			if (initial_check_a(st))
			{
				check_push_to_b(st);
				if (st->stack_a[st->top_a] <= st->median)
					push_b(st);
			}
		}
		i++;
	}
}

void	part_a(t_stack *st)
{
	int	j;

	j = 0;
	st->limit = limit_calc(st);
	while (st->top_a > 1 && j < st->limit)
	{
		fix_yourself(st, 1);
		find_tools(st, 1);
		algo(st);
		free_yourself(st);
		j++;
	}
	apply_small_algo_a(st);
}

void	big_algo(t_stack *st)
{
	part_a(st);
	part_b(st);
}
