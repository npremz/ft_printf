/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:52:08 by npremont          #+#    #+#             */
/*   Updated: 2023/10/16 15:55:59 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = NULL;
	elem = (t_list *)malloc(sizeof(t_list));
	if (elem)
	{
		elem->content = content;
		elem->next = NULL;
	}
	return (elem);
}
