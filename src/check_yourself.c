/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_yourself.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:25:30 by aaljaber          #+#    #+#             */
/*   Updated: 2023/03/25 01:47:30 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	is_sort(t_stack *st)
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
	free_yourself(st);
	return (1);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i = 1;
		while (str[i])
		{
			if (str[i] >= '0' && str[i] <= '9')
				i++;
			else
				return (0);
		}
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check(int num, int *arr, int i)
{
	int	k;

	k = 0;
	while (k < i)
	{
		if (num == arr[k])
			return (1);
		k++;
	}
	return (0);
}

int	is_dup(t_stack *st)
{
	int	i;

	i = 0;
	while (i < st->ele_tot)
	{
		if (check(st->stack_a[i], st->stack_a, i))
			return (1);
		i++;
	}
	return (0);
}

int	str_space(const char *s, int c)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)s;
	while (result[i] != '\0' && result[i] != (char) c)
		i++;
	if (result[i] == (char)c)
		return (1);
	return (0);
}
