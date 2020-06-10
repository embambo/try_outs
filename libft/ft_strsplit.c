/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:35:22 by ashongwe          #+#    #+#             */
/*   Updated: 2019/06/13 15:58:37 by ashongwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_wcount(const char *s, char c)
{
	size_t	ctrl;
	int		num;

	ctrl = 0;
	num = 0;
	if (s[ctrl] != c)
		num++;
	while (s[ctrl])
	{
		if (s[ctrl] == c && s[ctrl + 1] != c && s[ctrl + 1] != '\0')
			num++;
		ctrl++;
	}
	return (num);
}

static	int			ft_len(const char *s, char c)
{
	int		ctrl;

	ctrl = 0;
	while (s[ctrl] && s[ctrl] != c)
		ctrl++;
	return (ctrl);
}

static char			**ft_split(char const *s, char c, size_t i, size_t row)
{
	size_t	col;
	char	**a;

	if (!(a = (char**)malloc(sizeof(char*) * ft_wcount(s, c) + 1)))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			col = 0;
			if (!(a[row] = (char*)malloc(sizeof(char) * ft_len(&s[i], c) + 1)))
				return (NULL);
			else
			{
				while (s[i] && s[i] != c)
					a[row][col++] = s[i++];
				a[row][col] = '\0';
				row++;
			}
		}
	}
	a[row] = 0;
	return (a);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t		ctrl;
	size_t		col;

	ctrl = 0;
	col = 0;
	if (!s)
		return (NULL);
	return (ft_split(s, c, ctrl, col));
}
