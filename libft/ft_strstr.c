/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:20:34 by ashongwe          #+#    #+#             */
/*   Updated: 2019/06/14 09:01:43 by ashongwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		row;
	size_t		column;
	char		*haystac;
	char		*needl;

	row = 0;
	haystac = (char*)haystack;
	needl = (char*)needle;
	if (needl[0] == '\0')
		return (haystac);
	while (haystac[row])
	{
		column = 0;
		while (haystac[row + column] == needl[column])
		{
			if (needl[column + 1] == '\0')
				return (&haystac[row]);
			column++;
		}
		row++;
	}
	return (NULL);
}
