/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 08:54:33 by ashongwe          #+#    #+#             */
/*   Updated: 2019/06/13 16:57:16 by ashongwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			ctrl;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	ctrl = 0;
	while (ctrl < n)
	{
		dest[ctrl] = source[ctrl];
		if (dest[ctrl] == (unsigned char)c)
			return ((void*)(dest + ctrl + 1));
		++ctrl;
	}
	return (NULL);
}
