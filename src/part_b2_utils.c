/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_b2_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:03:27 by aaljaber          #+#    #+#             */
/*   Updated: 2023/03/25 01:47:30 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	is_sooort(t_stack *st)
{
	int	i;
	int	j;

	i = -1;
	j = st->top_a;
	fix_yourself(st, 1);
	while (++i < st->ele_tot)
	{
		if (st->stack_a[j--] != st->doo.array_yourself[i])
			return (0);
	}
	if (st->top_a == st->ele_tot - 1)
	{
		free_yourself(st);
		return (1);
	}
	return (0);
}

int	initial_check_b(t_stack *st)
{
	int	i;

	i = st->top_b;
	while (i-- > 0)
	{
		if (st->stack_b[i] >= st->big_nums)
			return (1);
	}
	return (0);
}

void	find_range(t_stack *st)
{
	int	m;

	m = 0;
	if (st->ele_tot < 500)
		m = st->doo.total_yourself - 5;
	if (st->ele_tot > 100)
		m = st->doo.total_yourself - 13;
	st->big_nums = st->doo.array_yourself[m];
	st->num_push = st->doo.total_yourself - m;
}

void	choose_range(t_stack *st)
{
	if (st->ele_tot < 500)
	{
		st->i = 100;
		st->r = 6;
	}
	if (st->ele_tot > 100)
	{
		st->i = 700;
		st->r = 13;
	}
}
