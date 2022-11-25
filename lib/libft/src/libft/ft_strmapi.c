/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@42kocaeli.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:22:54 by yerkiral          #+#    #+#             */
/*   Updated: 2022/02/02 22:17:21 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*final;

	i = 0;
	if (s)
	{
		final = ft_strdup(s);
		if (!(final))
			return (NULL);
		while (s[i] != '\0')
		{
			final[i] = (*f)(i, s[i]);
			i++;
		}
		final[i] = '\0';
		return (final);
	}
	return (NULL);
}
