/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:29:25 by ashongwe          #+#    #+#             */
/*   Updated: 2019/08/20 11:24:35 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char  *s1, char  *s2)
{
	if (!s1 || !s2)
		return (0);
	if (!ft_strcmp(s1, s2))
		return (1);
	return (0);
}
