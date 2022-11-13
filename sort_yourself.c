/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_yourself.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:20:41 by aaljaber          #+#    #+#             */
/*   Updated: 2022/02/03 13:20:45 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_yourself(t_stack *st)
{
	free (st->doo.array_yourself);
	st->doo.pivot_yourself = 0;
	st->doo.total_yourself = 0;
	st->median = 0;
}

static void	swap_yourself(int *b, int *e)
{
	int	temp;

	temp = *b;
	*b = *e;
	*e = temp;
}

static int	part_yourself(int *arr_yourself, \
		int begin_yourself, int end_yourself)
{
	int	pivot_yourself;
	int	i;
	int	j;

	pivot_yourself = arr_yourself[end_yourself];
	i = begin_yourself - 1;
	j = begin_yourself;
	while (j <= end_yourself - 1)
	{
		if (arr_yourself[j] < pivot_yourself)
		{
			i++;
			swap_yourself(&arr_yourself[i], &arr_yourself[j]);
		}
		j++;
	}
	swap_yourself(&arr_yourself[i + 1], &arr_yourself[end_yourself]);
	return (i + 1);
}

void	sort_yourself(int *arr_yourself, \
		int begin_yourself, int end_yourself)
{
	int	repart_yourself;

	if (begin_yourself < end_yourself)
	{
		repart_yourself = part_yourself(arr_yourself, \
				begin_yourself, end_yourself);
		sort_yourself(arr_yourself, begin_yourself, repart_yourself - 1);
		sort_yourself(arr_yourself, repart_yourself + 1, end_yourself);
	}
}

/* quick sort used to check if stack a is already sorted or 
to find the median and for other median method purposes also
for while loops conditions etc.. */
void	count_yourself(t_stack *st, int k)
{
	int	i;

	if (k == 1)
	{
		st->doo.total_yourself = st->top_a + 1;
		st->doo.array_yourself = (int *)malloc((st->doo.total_yourself + 1) \
				* sizeof(int));
		i = -1;
		while (++i < st->doo.total_yourself)
			st->doo.array_yourself[i] = st->stack_a[i];
	}
	else if (k == 2)
	{
		st->doo.total_yourself = st->top_b + 1;
		st->doo.array_yourself = (int *)malloc((st->doo.total_yourself + 1) \
				* sizeof(int));
		i = -1;
		while (++i < st->doo.total_yourself)
			st->doo.array_yourself[i] = st->stack_b[i];
	}
}
