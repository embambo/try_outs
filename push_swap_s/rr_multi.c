/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_multi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:34:17 by embambo           #+#    #+#             */
/*   Updated: 2020/06/10 08:56:15 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common/push_swap.h"

/*
** Rotation number to be on the top of stack a
*/

int				ft_up_a(t_stack *stks, int index)
{
	int			num;

	if (index == stks->top_a)
		return (0);
	num = stks->top_a - index;
	if (num < 0)
		num = -1 * num;
	return (num);
}

int				ft_down_a(t_stack *stks, int index)
{
	if (index == stks->size - 1 && stks->elems_a == 1)
		return (0);
	return (stks->size - index);
}
