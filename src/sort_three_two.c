/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:19:47 by aaljaber          #+#    #+#             */
/*   Updated: 2023/03/25 01:47:30 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/* if(st->stack_a[st->top_a - 1] < st->stack_a[0])
if(st->stack_a[st->top_a] < st->stack_a[0])
Already sorted*/
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

/* There are 6 cases to handle for this algo
therefore we got 6 conditions in here for sorting 3 numbers
to organize these 6 conditions, separate them in two conditions
when top > second else top < second etc...
the commands i figured them out manually */
void	three_algo(t_stack *st)
{
	if (st->stack_a[st->top_a] < st->stack_a[st->top_a - 1])
		small_topcheck(st);
	else if (st->stack_a[st->top_a] > st->stack_a[st->top_a - 1])
		big_topcheck(st);
}

/*if(st->stack_a[st->top_a] < st->stack_a[0])
Already sorted*/
void	two_algo(t_stack *st)
{
	if (st->stack_a[st->top_a] > st->stack_a[0])
		swap_a(st);
}
