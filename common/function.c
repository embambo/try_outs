/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 09:38:11 by embambo           #+#    #+#             */
/*   Updated: 2020/06/10 08:38:42 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_oper				*ft_new_oper(char *str)
{
	t_oper			*new;

	new = (t_oper*)malloc(sizeof(t_oper) * 1);
	new->oper = str;
	new->command = -1;
	new->num = 0;
	new->next = NULL;
	new->holder = NULL;
	return (new);
}

void				ft_add_oper(t_oper **commands, t_oper **new)
{
	static t_oper	*holder;
	static int		flag;

	if (*commands != NULL)
	{
		if (flag == 0)
			holder = *new;
		if (flag > 0)
		{
			holder->next = *new;
			holder = *new;
		}
		else
			(*commands)->next = *new;
		flag = 1;
	}
	else
		*commands = *new;
}

void				ft_free_commands(t_oper **commands)
{
	t_oper			*copy;
	t_oper			*holder;

	copy = *commands;
	if (copy == NULL)
		return ;
	while (copy)
	{
		holder = copy->next;
		if (copy->oper)
			free(copy->oper);
		free(copy);
		copy = NULL;
		copy = holder;
	}
	*commands = NULL;
}

void				ft_print_commands(t_oper *commands)
{
	t_oper		*copy;

	copy = commands;
	if (!copy)
		return ;
	while (copy)
	{
		ft_putstr(copy->oper);
		copy = copy->next;
	}
}
