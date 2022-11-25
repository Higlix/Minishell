/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@42kocaeli.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:15:57 by yerkiral          #+#    #+#             */
/*   Updated: 2022/02/01 23:17:21 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*_new_node;

	_new_node = (t_list *) malloc(sizeof(t_list));
	if (!(_new_node))
		return (_new_node = NULL);
	_new_node->content = content;
	_new_node->next = NULL;
	return (_new_node);
}
