/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@42kocaeli.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:12:05 by yerkiral          #+#    #+#             */
/*   Updated: 2022/02/02 21:19:30 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*final;

	final = (void *) malloc(size * count);
	if (!final)
		return (NULL);
	ft_bzero(final, count * size);
	return (final);
}
