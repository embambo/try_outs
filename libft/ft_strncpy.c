/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:03:09 by ashongwe          #+#    #+#             */
/*   Updated: 2019/06/14 08:01:04 by ashongwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		control;

	control = 0;
	while (src[control] && control < len)
	{
		dst[control] = src[control];
		control++;
	}
	while (control < len)
	{
		dst[control] = '\0';
		control++;
	}
	return (dst);
}
