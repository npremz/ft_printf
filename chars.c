/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:01:54 by npremont          #+#    #+#             */
/*   Updated: 2023/10/19 18:07:19 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int		len;
	char	*nullstr;

	nullstr = "(null)";
	if (str == NULL)
	{
		len = ft_strlen(nullstr);
		if (write(1, nullstr, len) == -1)
			return (-1);
	}
	else
	{
		len = ft_strlen(str);
		if (write(1, str, len) == -1)
			return (-1);
	}
	return (len);
}
