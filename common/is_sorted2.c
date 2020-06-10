/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:07:02 by embambo           #+#    #+#             */
/*   Updated: 2020/06/10 08:39:37 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_free_2d_array(char **array, int size)
{
	int			index;

	index = 0;
	if (!array)
		return (-1);
	while (index < size)
	{
		if (array[index])
			free(array[index]);
		index++;
	}
	free(array);
	return (-1);
}

void			printing_stack(char l[4], int z)
{
	while (z >= 0 || l)
	{
		ft_putchar(*l);
		ft_putendl(",");
		ft_putnbr(z);
		z++;
		l++;
	}
}
