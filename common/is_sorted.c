/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:07:02 by embambo           #+#    #+#             */
/*   Updated: 2020/06/10 08:38:56 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_no_change(t_stack *stks)
{
	if (stks->flag == 0)
		return ;
	printing_stack(stks->last, (stks->step)++);
	ft_putstr(stks->last);
}

int			ft_isinorder(int *tab, int size)
{
	int		index;

	index = 0;
	while (index < size - 1)
	{
		if (tab[index] < tab[index + 1])
			index++;
		else
			return (0);
	}
	return (1);
}

int			ft_is_stack_in_order(t_stack *stks)
{
	if (stks->elems_b == 0)
	{
		if (ft_isinorder(stks->stk_a, stks->size) == 1)
			return (1);
		else
			return (-1);
	}
	else
		return (-1);
}

void		ft_free_all(int *tab, t_stack *stks, t_oper **commands, int *flags)
{
	free(tab);
	if (stks)
	{
		free(stks->stk_b);
		free(stks);
	}
	if (commands)
		ft_free_commands(*&commands);
	free(flags);
}

int			ft_count_words(const char *str, char c)
{
	int i;

	i = 0;
	while (*str == c)
		str++;
	while (*str)
	{
		while (*str && *str != c)
			str++;
		while (*str == c)
			str++;
		i++;
	}
	return (i);
}
