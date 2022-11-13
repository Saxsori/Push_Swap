/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_b2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:42:44 by aaljaber          #+#    #+#             */
/*   Updated: 2022/02/02 21:53:53 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	scan_top_b(t_stack *st)
{
	int	i;

	i = st->top_b;
	while (i >= 0 && st->stack_b[i] < st->big_nums)
		i--;
	return (st->top_b - i);
}

static int	scan_bottom_b(t_stack *st)
{
	int	i;

	i = 0;
	while (i <= st->top_b && st->stack_b[i] < st->big_nums)
		i++;
	return (i);
}

void	check_push(t_stack *st)
{
	int	i;

	i = 0;
	st->top = scan_top_b(st);
	st->bottom = scan_bottom_b(st);
	if (initial_check_b(st) && \
			(st->bottom >= st->top || st->bottom == st->top - 1) \
			&& st->top_b > -1)
	{
		while (i <= st->top && st->stack_b[st->top_b] < st->big_nums)
		{
			rot_b(st);
			i++;
		}
	}
	else if (initial_check_b(st) && st->bottom < st->top && st->top_b > -1)
	{
		i = 0;
		while (i <= st->bottom && st->stack_b[st->top_b] < st->big_nums)
		{
			revrot_b(st);
			i++;
		}
	}
}

void	new_algo(t_stack *st)
{
	int	i;

	i = 0;
	while (initial_check_b(st) && i < st->num_push)
	{
		if (st->stack_b[st->top_b] >= st->big_nums)
			check_push_to_a(st);
		else
		{
			if (initial_check_b(st))
			{
				check_push(st);
				if (st->stack_b[st->top_b] >= st->big_nums)
					check_push_to_a(st);
			}
		}
		i++;
	}
}

void	check_push_to_a2(t_stack *st)
{
	choose_range(st);
	while (st->top_b - 1 > -2 && st->i-- > 0 && !is_sooort(st))
	{
		free_yourself(st);
		if (st->top_b >= st->r)
		{
			fix_yourself(st, 2);
			find_range(st);
			new_algo(st);
			free_yourself(st);
		}
		else if (st->top_b < st->r)
		{
			if (st->top_b > -1)
			{
				while (st->top_b > -1)
					check_push_to_a(st);
			}
			else
				push_a(st);
		}
	}
}
