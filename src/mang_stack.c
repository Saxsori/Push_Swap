/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mang_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:46:40 by aaljaber          #+#    #+#             */
/*   Updated: 2023/03/25 01:47:30 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	fill_stack(char **str, t_stack *st, int i)
{
	int	ele;

	st->stack_b = (int *)malloc(sizeof(int) * (st->ele_tot + 1));
	st->top_a = st->ele_tot - 1;
	st->top_b = -1;
	while (i < st->ele_tot)
	{
		ele = ft_atoi(str[i]);
		st->stack_a[st->top_a] = ele;
		st->top_a--;
		i++;
	}
	st->top_a = st->ele_tot - 1;
}

void	fill_stack2(char **str, t_stack *st, int i)
{
	int	ele;

	st->stack_b = (int *)malloc(sizeof(int) * (st->ele_tot));
	st->top_a = st->ele_tot - 1;
	st->top_b = -1;
	while (i < st->ele_tot + 1)
	{
		ele = ft_atoi(str[i]);
		st->stack_a[st->top_a] = ele;
		st->top_a--;
		i++;
	}
	st->top_a = st->ele_tot - 1;
}

void	single_arg(char **str, t_stack *st)
{
	check_single_arg(str, st);
	st->stack_a = (int *)malloc(sizeof(int) * (st->ele_tot + 1));
	st->doo.total_yourself = st->ele_tot + 1;
	if (!st->stack_a)
	{
		free(st->stack_a);
		free_split(str, st->ele_tot);
		exit(1);
	}
	fill_stack(str, st, 0);
	if (is_dup(st))
	{
		free_stack(st);
		free_split(str, st->ele_tot);
		err(3);
	}
}

void	multi_arg(char **str, int argc, t_stack *st)
{
	int	i;

	i = 1;
	st->ele_tot = argc - 1;
	while (i < argc)
	{
		if (is_numeric(str[i]) == 0)
			err(2);
		i++;
	}
	st->stack_a = (int *)malloc(sizeof(int) * (st->ele_tot));
	st->doo.total_yourself = st->ele_tot;
	if (!st->stack_a)
	{
		free(st->stack_a);
		exit(1);
	}
	fill_stack2(str, st, 1);
	if (is_dup(st))
	{
		free_stack(st);
		err(3);
	}
}

void	mang_stack(char **str, int argc, t_stack *st)
{
	int		k;
	char	**split;

	k = -1;
	if (argc == 2)
	{
		if (str_space(str[1], ' '))
		{
			split = ft_split(str[1], ' ');
			while (split[++k])
				st->ele_tot++;
			single_arg(split, st);
			free_split(split, st->ele_tot);
		}
		else
		{
			exit(0);	
		}
	}
	if (argc > 2)
		multi_arg(str, argc, st);
}
