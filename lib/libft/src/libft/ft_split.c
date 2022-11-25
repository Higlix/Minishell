/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@42kocaeli.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:04:20 by yerkiral          #+#    #+#             */
/*   Updated: 2022/02/04 14:56:05 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_getsep(char const *s, char c)
{
	size_t	i;
	long	nos;

	i = 0;
	nos = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			nos++;
			while (s[i] != c && s[i] != '\0')
				i++;
			continue ;
		}
		i++;
	}
	return (nos);
}

char	*ft_doop(size_t start, size_t i, char const *s, size_t len)
{
	char	*rtn;
	size_t	in;

	rtn = (char *) malloc(sizeof(char) * (len + 1));
	in = 0;
	while (start < i)
	{
		rtn[in] = s[start];
		in++;
		start++;
	}
	rtn[in] = '\0';
	return (rtn);
}

void	ft_final(long nos, char c, char **final, char const *s)
{
	long	done;
	size_t	i;
	size_t	start;

	done = 0;
	i = 0;
	while (done < nos)
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			final[done] = ft_doop(start, i, s, i - start);
			done++;
			continue ;
		}
		i++;
	}
	final[done] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	long	nos;

	if (!s)
		return (NULL);
	nos = ft_getsep(s, c);
	final = (char **) malloc(sizeof(char *) * (nos + 1));
	if (!final)
		return (0);
	ft_final(nos, c, final, s);
	if (final)
		return (final);
	else
		return (NULL);
}
