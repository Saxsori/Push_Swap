/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:18:04 by aaljaber          #+#    #+#             */
/*   Updated: 2023/03/25 01:47:30 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static void	first_push(t_stack *st)
{
	if (st->stack_b[st->top_b] > st->stack_a[st->top_a] \
			&& st->stack_b[st->top_b] < st->stack_a[st->top_a - 1])
	{
		push_a(st);
		swap_a(st);
	}
	if (st->stack_b[st->top_b] > st->stack_a[st->top_a - 1] \
			&& st->stack_b[st->top_b] < st->stack_a[0])
	{
		revrot_a(st);
		push_a(st);
		rot_a(st);
		rot_a(st);
	}
	if (st->stack_b[st->top_b] > st->stack_a[0])
	{
		push_a(st);
		rot_a(st);
	}
}

static void	condition_p1(t_stack *st)
{
	if (st->stack_b[st->top_b] < st->stack_a[st->top_a])
		push_a(st);
	if (st->stack_b[st->top_b] > st->stack_a[st->top_a] \
			&& st->stack_b[st->top_b] < st->stack_a[st->top_a - 1])
	{
		push_a(st);
		swap_a(st);
	}
	if (st->stack_b[st->top_b] > st->stack_a[st->top_a - 1] \
			&& st->stack_b[st->top_b] < st->stack_a[st->top_a - 2])
	{
		revrot_a(st);
		revrot_a(st);
		push_a(st);
		rot_a(st);
		rot_a(st);
		rot_a(st);
	}
}

static void	condition_p2(t_stack *st)
{
	if (st->stack_b[st->top_b] > st->stack_a[st->top_a - 2] \
			&& st->stack_b[st->top_b] < st->stack_a[st->top_a - 3])
	{
		revrot_a(st);
		push_a(st);
		rot_a(st);
		rot_a(st);
	}
	if (st->stack_b[st->top_b] > st->stack_a[0])
	{
		push_a(st);
		rot_a(st);
	}
}

static void	second_push(t_stack *st)
{
	condition_p1(st);
	condition_p2(st);
}

/*cuz i have 5 numbers it's hard 
 * if pushed the middle number to stack b
it will require a lot of moves so i 
wiil apply the median method and the case will be only 
moving one number greater than the 
middle number and one smaller then apply algo three on the remaining
numbers in stack a then find the 
correct spot for the number that i will push back to a*/
void	fivfor_algo(t_stack *st)
{
	find_median(st);
	if (st->ele_tot == 5)
	{
		find_push(st);
		three_algo(st);
		if (st->stack_b[st->top_b] < st->stack_b[0])
			swap_b(st);
		first_push(st);
		second_push(st);
	}
	if (st->ele_tot == 4)
	{
		push_b(st);
		three_algo(st);
		first_push(st);
	}
	free_yourself(st);
}
