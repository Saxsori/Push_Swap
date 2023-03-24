/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:04:53 by aaljaber          #+#    #+#             */
/*   Updated: 2023/03/25 01:47:30 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static int	scan_top(t_stack *st)
{
	int	i;

	i = st->top_a;
	while (i >= 0 && st->stack_a[i] < st->stack_b[st->top_b])
		i--;
	return (st->top_a - (i + 1));
}

static int	scan_bottom(t_stack *st)
{
	int	i;

	i = 0;
	while (st->stack_a[i] != st->mark_bottom \
			&& st->stack_a[i] > st->stack_b[st->top_b])
		i++;
	return (i - 1);
}

void	do_ra(t_stack *st)
{
	int	i;

	i = 0;
	st->small_num = scan_top(st);
	while (i <= st->small_num)
	{
		rot_a(st);
		i++;
	}
	push_a(st);
}

void	do_rra(t_stack *st)
{
	int	i;

	st->rra_num = scan_bottom(st);
	i = 0;
	while (i <= st->rra_num)
	{
		revrot_a(st);
		i++;
	}
	push_a(st);
}
