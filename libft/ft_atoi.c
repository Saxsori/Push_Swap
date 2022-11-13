/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:32:28 by aaljaber          #+#    #+#             */
/*   Updated: 2022/02/03 16:58:26 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "../push_swap.h"

void	chneg(const char *str, t_count *c)
{
	if (str[c->i] == '-')
	{
		c->n = -1;
		c->i++;
	}
	else if (str[c->i] == '+')
		c->i++;
}

int	ft_atoi(const char *str)
{
	long		result;
	t_count		c;

	c.i = 0;
	c.n = 1;
	result = 0;
	while ((str[c.i] >= 9 && str[c.i] <= 13) || str[c.i] == 32)
		c.i++;
	chneg(str, &c);
	while (str[c.i] != '\0' && str[c.i] >= '0' && str[c.i] <= '9')
	{
		result *= 10;
		result += str[c.i] - '0';
		c.i++;
	}
	result = result * c.n;
	if (result > 2147483647 || result < -2147483648)
		err(4);
	return (result);
}
