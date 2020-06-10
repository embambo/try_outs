/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:26:43 by ashongwe          #+#    #+#             */
/*   Updated: 2019/06/14 08:06:04 by ashongwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	unsigned int pos;
	unsigned int i;

	if (!*n)
		return ((char*)h);
	pos = 0;
	while (h[pos] != '\0' && (size_t)pos < len)
	{
		if (h[pos] == n[0])
		{
			i = 1;
			while (n[i] != '\0' && h[pos + i] == n[i] &&
					(size_t)(pos + i) < len)
				++i;
			if (n[i] == '\0')
				return ((char*)&h[pos]);
		}
		++pos;
	}
	return (0);
}
