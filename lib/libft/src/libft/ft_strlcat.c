/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@42kocaeli.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:35:46 by yerkiral          #+#    #+#             */
/*   Updated: 2022/02/01 16:15:09 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	i;
	size_t	srcl;
	size_t	dstl;

	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	i = dstl;
	j = 0;
	if (dstsize == 0)
		return (srcl);
	if (dstsize < dstl)
		return (srcl + dstsize);
	else
	{
		while (src[j] && (dstl + j) < dstsize)
			dst[i++] = src[j++];
		if ((dstl + j) == dstsize && dstl < dstsize)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (srcl + dstl);
	}
}
