/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 01:04:06 by npremont          #+#    #+#             */
/*   Updated: 2023/10/18 11:06:00 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*str;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	while (s1[end] != '\0')
		++end;
	while (ft_isinset(s1[start], set) == 1 && s1[start])
		++start;
	while (ft_isinset(s1[end - 1], set) == 1 && s1[end - 1])
		--end;
	if (end > start)
		str = (char *)malloc(sizeof(char) * (end - start + 1));
	else
		str = (char *)malloc(1);
	if (str == NULL)
		return (NULL);
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
