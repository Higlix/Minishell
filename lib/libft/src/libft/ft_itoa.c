/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@42kocaeli.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:48:02 by yerkiral          #+#    #+#             */
/*   Updated: 2022/02/02 23:22:40 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_getsize(int n)
{
	int	nega;
	int	dec;

	dec = 0;
	nega = 0;
	if (n < 0)
	{
		nega++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		dec++;
	}
	return (dec + nega);
}

char	*ft_op(char *s, int n, size_t size)
{
	int	is_neg;

	is_neg = -1;
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
	}
	s[size] = '\0';
	while (--size)
	{
		s[size] = (n % 10) + 48;
		n /= 10;
	}
	if (is_neg == 1)
		s[0] = '-';
	else
		s[0] = (n % 10) + 48;
	return (s);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*final;

	size = ft_getsize(n);
	if (size == 0)
	{
		final = (char *) malloc(2);
		final[0] = '0';
		final[1] = '\0';
		return (final);
	}
	if (n == -2147483648)
	{
		final = ft_strdup("-2147483648");
		final[11] = '\0';
		return (final);
	}
	final = (char *) malloc(sizeof(char) * (size + 1));
	if (!final)
		return (NULL);
	final = ft_op(final, n, size);
	return (final);
}
