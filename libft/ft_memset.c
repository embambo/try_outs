/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 07:40:35 by ashongwe          #+#    #+#             */
/*   Updated: 2019/06/13 17:01:35 by ashongwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			a;
	unsigned char	b;
	unsigned char	*pointer;

	a = 0;
	b = (unsigned char)c;
	pointer = (unsigned char*)str;
	while (a < n)
	{
		pointer[a] = b;
		a++;
	}
	return (str);
}
