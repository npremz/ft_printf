/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:17:15 by npremont          #+#    #+#             */
/*   Updated: 2023/10/17 13:51:53 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = c;
	while (*s)
	{
		if (ch == *s)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}
