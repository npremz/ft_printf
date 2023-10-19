/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:39:28 by npremont          #+#    #+#             */
/*   Updated: 2023/10/17 13:19:03 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res_str;
	int		i;

	i = 0;
	res_str = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!res_str)
		return (NULL);
	while (s[i])
	{
		res_str[i] = (*f)(i, s[i]);
		i++;
	}
	res_str[i] = '\0';
	return (res_str);
}
