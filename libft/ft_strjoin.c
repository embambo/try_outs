/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:35:21 by ashongwe          #+#    #+#             */
/*   Updated: 2019/06/14 07:49:25 by ashongwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length;
	char	*freshstring;

	if (!s1 || !s2)
		return (0);
	length = ft_strlen(s1) + ft_strlen(s2);
	freshstring = (char*)malloc(sizeof(char) * (length + 1));
	if (freshstring == NULL)
		return (NULL);
	ft_strcpy(freshstring, (char*)s1);
	ft_strcat(freshstring, (char*)s2);
	return (freshstring);
}
