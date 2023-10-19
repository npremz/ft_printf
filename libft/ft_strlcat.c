/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:09:19 by npremont          #+#    #+#             */
/*   Updated: 2023/10/17 13:44:21 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_size;
	size_t	src_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen((char *)src);
	j = dst_size;
	i = 0;
	if (dstsize == 0 || dstsize <= dst_size)
		return (src_size + dstsize);
	while (src[i] != '\0' && i < dstsize - dst_size - 1)
	{
		dst[j] = src[i];
		++i;
		++j;
	}
	dst[j] = '\0';
	return (dst_size + src_size);
}
