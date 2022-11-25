/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@42kocaeli.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:17:30 by yerkiral          #+#    #+#             */
/*   Updated: 2022/02/02 00:20:43 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*dump;
	t_list	*next;

	dump = *lst;
	while (dump)
	{
		(*del)(dump->content);
		next = dump->next;
		free(dump);
		dump = next;
	}
	*lst = NULL;
}
