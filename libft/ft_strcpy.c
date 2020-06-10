/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:33:50 by ashongwe          #+#    #+#             */
/*   Updated: 2019/06/14 07:37:47 by ashongwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destination, const char *source)
{
	size_t		control;

	control = 0;
	while (source[control])
	{
		destination[control] = source[control];
		control++;
	}
	destination[control] = '\0';
	return (destination);
}
