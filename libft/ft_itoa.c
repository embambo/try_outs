/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:47:52 by ashongwe          #+#    #+#             */
/*   Updated: 2019/06/21 12:40:09 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_num_len(int num)
{
	int			len;

	len = 1;
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num > 9)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static int		ft_div(int len)
{
	int		div;

	div = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		div *= 10;
		len--;
	}
	return (div);
}

char			*ft_itoa(int n)
{
	int		ctrl;
	int		len;
	int		maxlen;
	char	*res;

	len = ft_num_len(n);
	maxlen = len;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ctrl = 0;
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
		ctrl++;
		len--;
	}
	while (ctrl < maxlen)
		res[ctrl++] = (((n / ft_div(len--)) % 10) + 48);
	res[ctrl++] = '\0';
	return (res);
}
