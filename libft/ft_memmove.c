/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:53:07 by npremont          #+#    #+#             */
/*   Updated: 2023/10/17 14:17:55 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*dst_str;
	char	*src_str;

	dst_str = (char *)dst;
	src_str = (char *)src;
	if (src < dst && dst - src < (int)len)
	{
		i = len - 1;
		while (i >= 0)
		{
			dst_str[i] = src_str[i];
			i--;
		}
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
