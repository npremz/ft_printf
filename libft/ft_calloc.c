/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:57:13 by npremont          #+#    #+#             */
/*   Updated: 2023/10/18 12:18:27 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	total = count * size;
	if (size && total / size != count)
		return (NULL);
	ptr = (void *)malloc(total);
	if (ptr != NULL)
		ft_memset(ptr, 0, total);
	return (ptr);
}
