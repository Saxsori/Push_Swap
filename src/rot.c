/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:17:23 by aaljaber          #+#    #+#             */
/*   Updated: 2023/03/25 01:47:30 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	rot_a(t_stack *st)
{
	int	temp;
	int	i;

	temp = st->stack_a[st->top_a];
	i = 0;
	while (i < st->top_a)
	{
		st->stack_a[st->top_a - i] = st->stack_a[st->top_a - (i + 1)];
		i++;
	}
	st->stack_a[0] = temp;
	ft_putstr_fd("ra\n", 1);
}

void	rot_b(t_stack *st)
{
	int	temp;
	int	i;

	temp = st->stack_b[st->top_b];
	i = 0;
	while (i < st->top_b)
	{
		st->stack_b[st->top_b - i] = st->stack_b[st->top_b - (i + 1)];
		i++;
	}
	st->stack_b[0] = temp;
	ft_putstr_fd("rb\n", 1);
}

void	rot_ab(t_stack *st)
{
	int	temp;
	int	i;

	temp = st->stack_a[st->top_a];
	i = 0;
	while (i < st->top_a)
	{
		st->stack_a[st->top_a - i] = st->stack_a[st->top_a - (i + 1)];
		i++;
	}
	st->stack_a[0] = temp;
	temp = 0;
	temp = st->stack_b[st->top_b];
	i = 0;
	while (i < st->top_b)
	{
		st->stack_b[st->top_b - i] = st->stack_b[st->top_b - (i + 1)];
		i++;
	}
	st->stack_b[0] = temp;
	ft_putstr_fd("rr\n", 1);
}
