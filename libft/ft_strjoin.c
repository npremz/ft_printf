/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:00:00 by npremont          #+#    #+#             */
/*   Updated: 2023/10/18 11:05:42 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_stradd(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		*dest = src[i];
		i++;
		dest++;
	}
	return (dest);
}

char	*ft_strjoin(char *prefix, char *suffix)
{
	char			*str;
	unsigned long	str_size;

	str_size = ft_strlen(prefix) + ft_strlen(suffix);
	str = malloc((str_size + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	str = ft_stradd(str, prefix);
	str = ft_stradd(str, suffix);
	*str = '\0';
	return (str - str_size);
}
