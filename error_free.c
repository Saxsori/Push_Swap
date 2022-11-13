/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:36:28 by aaljaber          #+#    #+#             */
/*   Updated: 2022/02/03 12:40:16 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **str, int tot)
{
	int	i;

	i = 0;
	while (i < tot)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack *st)
{
	free (st->stack_a);
	free (st->stack_b);
}

void	check_single_arg(char **str, t_stack *st)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_numeric(str[i]) == 0)
		{
			free_split(str, st->ele_tot);
			err(2);
		}
		i++;
	}
}

void	err(int op)
{
	if (op == 2)
		ft_putstr_fd("Error\n", 1);
	if (op == 3)
		ft_putstr_fd("Error\n", 1);
	if (op == 4)
		ft_putstr_fd("Error\n", 1);
	exit(1);
}
