/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@42kocaeli.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:48:02 by yerkiral          #+#    #+#             */
/*   Updated: 2022/02/03 18:26:41 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim_start(const char *s, const char *set)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
			{
				i++;
				break ;
			}
			j++;
		}
		if (!set[j])
			break ;
	}
	return (i);
}

static int	ft_trim_end(const char *s, const char *set)
{
	int	i;
	int	j;

	i = ft_strlen(s) - 1;
	while (s[i])
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
			{
				i--;
				break ;
			}
			j++;
		}
		if (!set[j])
			break ;
	}
	return (i);
}

char	*ft_strtrim(const char *s, const char *set)
{
	int		i;
	int		j;
	int		index;
	char	*ptr;

	ptr = NULL;
	if (s && set)
	{
		i = ft_trim_end(s, set);
		j = ft_trim_start(s, set);
		if (i < j)
			return (ft_strdup(""));
		ptr = malloc (sizeof(char) * ((i + 1) - j + 1));
		if (!ptr)
			return (NULL);
			index = 0;
		while (j <= i)
		{
			ptr[index] = s[j];
			index++;
			j++;
		}
		ptr[index] = '\0';
	}
	return (ptr);
}
