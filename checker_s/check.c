/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:06:58 by embambo           #+#    #+#             */
/*   Updated: 2020/06/10 10:43:12 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common/push_swap.h"

static char		*ft_game_read(void)
{
	char		*argument;
	char		buf[2];

	buf[0] = '\0';
	buf[1] = '\0';
	argument = NULL;
	if (read(0, buf, 1) == -1)
		return (NULL);
	buf[1] = '\0';
	argument = ft_strnew(2);
	ft_memcpy(argument, buf, 1);
	argument[1] = '\0';
	return (argument);
}

static void		ft_play_again(t_stack *stks, t_stack **stks_copy,
								int **a_copy, int code)
{
	int			index;
	int			flags[2];

	if (code == 0)
	{
		*a_copy = (int*)malloc(sizeof(int) * stks->size);
		index = -1;
		while (++index < stks->size)
			(*a_copy)[index] = stks->stk_a[index];
	}
	else if (code == 1)
	{
		flags[0] = 1;
		flags[1] = 1;
		*stks_copy = ft_new_stks(*a_copy, stks->size, flags);
		ft_game_mode(*stks_copy);
		free((*stks_copy)->stk_a);
		free((*stks_copy)->stk_b);
		free(*stks_copy);
	}
	else
		free(*a_copy);
}

static void		ft_first_launch(t_stack *stks, t_history **history)
{
	ft_putstr("NEW GAME started\n");
	ft_print_list_of_commands();
	ft_print_stacks(stks);
	*history = NULL;
}

void			ft_game_mode(t_stack *stks)
{
	char		*argument;
	t_history	*history;
	int			code;
	int			*a_copy;
	t_stack		*stks_copy;

	code = 0;
	ft_play_again(stks, &stks_copy, &a_copy, code);
	ft_first_launch(stks, &history);
	while (1)
	{
		if ((argument = ft_game_read()) == NULL)
			break ;
		if (*argument == '\n')
		{
			free(argument);
			continue ;
		}
		history = ft_add_history(&history, argument);
		if ((code = ft_game_act(argument, stks, history)) == -1 || code == 1)
			break ;
	}
	ft_clean_the_game_history(&history);
	ft_putstr("GAME END\n");
	ft_play_again(stks, &stks_copy, &a_copy, code);
}
