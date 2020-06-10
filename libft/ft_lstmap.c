/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:55:09 by ashongwe          #+#    #+#             */
/*   Updated: 2019/06/13 16:45:16 by ashongwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlink;

	if (!lst)
		return (NULL);
	newlink = f(lst);
	newlink->next = ft_lstmap(lst->next, f);
	return (newlink);
}
