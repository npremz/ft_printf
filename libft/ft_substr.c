/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 01:04:47 by npremont          #+#    #+#             */
/*   Updated: 2023/10/17 18:12:16 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*str;

	i = 0;
	j = 0;
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i <= start && s[i] != '\0')
	{
		if (i == start)
		{
			while (s[i] != '\0' && j < len)
				str[j++] = s[i++];
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
