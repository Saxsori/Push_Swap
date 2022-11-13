/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:16:39 by aaljaber          #+#    #+#             */
/*   Updated: 2022/02/03 13:16:43 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrot_a(t_stack *st)
{
	int	temp;
	int	i;

	temp = st->stack_a[0];
	i = 0;
	while (i < st->top_a)
	{
		st->stack_a[i] = st->stack_a[i + 1];
		i++;
	}
	st->stack_a[st->top_a] = temp;
	ft_putstr_fd("rra\n", 1);
}

void	revrot_b(t_stack *st)
{
	int	temp;
	int	i;

	temp = st->stack_b[0];
	i = 0;
	while (i < st->top_b)
	{
		st->stack_b[i] = st->stack_b[i + 1];
		i++;
	}
	st->stack_b[st->top_b] = temp;
	ft_putstr_fd("rrb\n", 1);
}

void	revrot_ab(t_stack *st)
{
	int	temp;
	int	i;

	temp = st->stack_a[0];
	i = 0;
	while (i < st->top_a)
	{
		st->stack_a[i] = st->stack_a[i + 1];
		i++;
	}
	st->stack_a[st->top_a] = temp;
	temp = 0;
	temp = st->stack_b[0];
	i = 0;
	while (i < st->top_b)
	{
		st->stack_b[i] = st->stack_b[i + 1];
		i++;
	}
	st->stack_b[st->top_b] = temp;
	ft_putstr_fd("rrr\n", 1);
}
