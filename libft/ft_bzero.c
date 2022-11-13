/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:07:14 by aaljaber          #+#    #+#             */
/*   Updated: 2022/01/30 16:15:29 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*j;

	j = (char *)s;
	if (n != 0)
	{
		j = (char *)ft_memset(s, '\0', n);
	}
	return ((void) j);
}
