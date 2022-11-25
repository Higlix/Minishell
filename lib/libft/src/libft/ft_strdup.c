/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@42kocaeli.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:33:03 by yerkiral          #+#    #+#             */
/*   Updated: 2022/02/01 14:33:04 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*final;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	final = (char *) malloc(sizeof(char) * (len + 1));
	if (!final)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		final[i] = s1[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}
