/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 09:47:12 by ashongwe          #+#    #+#             */
/*   Updated: 2019/06/13 16:59:09 by ashongwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			a;
	unsigned char	target;
	unsigned char	*st;

	a = 0;
	target = (unsigned char)c;
	st = (unsigned char*)str;
	while (a < n)
	{
		if (st[a] == target)
			return (&st[a]);
		a++;
	}
	return (NULL);
}
