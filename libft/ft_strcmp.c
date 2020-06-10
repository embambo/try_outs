/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:47:34 by ashongwe          #+#    #+#             */
/*   Updated: 2019/08/13 15:27:17 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t		control;

	control = 0;
	while (s1[control] && s2[control] && s1[control] == s2[control])
		control++;
	if (((unsigned char)s1[control] - (unsigned char)s2[control]) < 0)
		return (-1);
	else if (((unsigned char)s1[control] - (unsigned char)s2[control]) > 0)
		return (1);
	else
		return (0);
}
