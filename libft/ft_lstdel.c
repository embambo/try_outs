/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:18:44 by ashongwe          #+#    #+#             */
/*   Updated: 2019/06/13 12:59:56 by ashongwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*newlink;
	t_list	*temp;

	if (!(*alst))
		return ;
	newlink = *alst;
	while (newlink != NULL)
	{
		temp = newlink->next;
		del(newlink, newlink->content_size);
		newlink = temp;
	}
	*alst = NULL;
}
