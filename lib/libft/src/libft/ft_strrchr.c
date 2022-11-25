/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@42kocaeli.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:48:30 by yerkiral          #+#    #+#             */
/*   Updated: 2022/02/02 20:20:03 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = 0;
	if (c > 255)
		c -= 256;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			p = (char *)(s + i);
		i++;
	}
	if (s[i] == c)
		p = (char *)(s + i);
	return (p);
}
