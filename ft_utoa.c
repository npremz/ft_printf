/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:41:17 by npremont          #+#    #+#             */
/*   Updated: 2023/10/19 17:52:37 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getstrsize(long unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

static char	*ft_putnbr_in_str(long unsigned int nb, char *str, int pos)
{
	if (nb < 10)
	{
		str[pos] = nb + 48;
	}
	else
	{
		ft_putnbr_in_str(nb / 10, str, pos - 1);
		str[pos] = nb % 10 + 48;
	}
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		str_size;

	str_size = ft_getstrsize(n);
	str = malloc((str_size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[str_size] = '\0';
	str = ft_putnbr_in_str(n, str, str_size - 1);
	return (str);
}
