/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:56:46 by aaljaber          #+#    #+#             */
/*   Updated: 2023/03/25 01:47:30 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	find_tools(t_stack *st, int t)
{
	int	m;

	if (t == 1)
		find_median(st);
	else if (t == 2)
	{
		m = st->doo.total_yourself / 2;
		st->range_size = m + 1;
		st->median = st->doo.array_yourself[m];
	}
}

int	scan_top_a(t_stack *st)
{
	int	i;

	i = st->top_a;
	while (i >= 0 && st->stack_a[i] >= st->median)
		i--;
	return (st->top_a - i);
}

int	scan_bottom_a(t_stack *st)
{
	int	i;

	i = 0;
	while (i <= st->top_a && st->stack_a[i] >= st->median)
		i++;
	return (i);
}

int	initial_check_a(t_stack *st)
{
	int	i;

	i = st->top_a;
	while (i-- > 0)
	{
		if (st->stack_a[i] <= st->median)
			return (1);
	}
	return (0);
}

void	apply_small_algo_a(t_stack *st)
{
	if (st->top_a > 5)
	{
		fix_yourself(st, 1);
		find_tools(st, 2);
		algo (st);
		free_yourself(st);
	}
	if (st->top_a + 1 == 5 || st->top_a + 1 == 4)
		small_algo(st);
	if (st->top_a + 1 == 3)
		three_algoo(st);
	if (st->top_a + 1 == 2 && st->stack_a[st->top_a] > st->stack_a[0])
		swap_a(st);
}
