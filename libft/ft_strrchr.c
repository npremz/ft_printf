/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:45:45 by npremont          #+#    #+#             */
/*   Updated: 2023/10/17 13:57:44 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*rtnval;

	ch = c;
	rtnval = 0;
	while (*s)
	{
		if (ch == *s)
			rtnval = (char *)s;
		s++;
	}
	if (*s == ch)
		rtnval = (char *)s;
	return (rtnval);
}
