/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:08:27 by ashongwe          #+#    #+#             */
/*   Updated: 2019/06/13 17:01:04 by ashongwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (&dst[0] < &src[0])
		return (ft_memcpy(dst, src, len));
	destination = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (!dst && !src && len > 0)
		return (NULL);
	while (len > 0)
	{
		destination[len - 1] = source[len - 1];
		len--;
	}
	return (dst);
}
