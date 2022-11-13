/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mang_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:44:33 by aaljaber          #+#    #+#             */
/*   Updated: 2022/02/03 13:01:53 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_median(t_stack *st)
{
	int	m;

	m = 0;
	if (st->ele_tot < 500)
	{
		m = st->doo.total_yourself / HUND_CHUNK;
		st->range_size = m + 1;
	}
	else if (st->ele_tot > 100)
	{
		m = st->doo.total_yourself / FIHUND_CHUNK;
		st->range_size = m + 1;
	}
	else if (st->ele_tot == 5)
	{
		m = st->doo.total_yourself / 2;
		st->range_size = m + 1;
	}
	st->median = st->doo.array_yourself[m];
}

void	fix_yourself(t_stack *st, int k)
{
	if (k == 1)
		count_yourself(st, 1);
	else if (k == 2)
		count_yourself(st, 2);
	sort_yourself(st->doo.array_yourself, 0, st->doo.total_yourself - 1);
}
