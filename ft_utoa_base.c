/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:12:55 by npremont          #+#    #+#             */
/*   Updated: 2023/10/20 12:42:50 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_putnbr_str(unsigned long int n, char *str, char *base, int pos)
{
	unsigned int	baselen;

	baselen = ft_strlen(base);
	if (n < 0)
	{
		str[0] = '-';
		return (ft_putnbr_str(n * -1, str, base, pos + 1));
	}
	else
	{
		if (n < baselen)
		{
			str[pos] = base[n];
		}
		else
		{
			ft_putnbr_str(n / baselen, str, base, pos - 1);
			str[pos] = base[n % baselen];
		}
		return (str);
	}
}

static char	*ft_str_alloc(unsigned int n, int size)
{
	char	*str;

	if (n < 0)
	{
		str = malloc(size * sizeof(char) + 2);
		if (!str)
			return (NULL);
		str[size + 1] = '\0';
	}
	else 
	{
		str = malloc(size * sizeof(char) + 1);
		if (!str)
			return (NULL);
		str[size] = '\0';
	}
	return (str);
}

char	*ft_utoa_base(unsigned int n, char *base)
{
	char				*str;
	unsigned int		baselen;
	unsigned long int	og_nbr;
	unsigned int		i;
	unsigned long int	nbr;

	baselen = ft_strlen(base);
	nbr = n;
	og_nbr = nbr;
	i = 1;
	if (nbr < 0)
		nbr *= -1;
	while (nbr >= baselen)
	{
		nbr = nbr / baselen;
		i++;
	}
	str = ft_str_alloc(og_nbr, i);
	if (!str)
		return (NULL);
	str = ft_putnbr_str(og_nbr, str, base, i - 1);
	return (str);
}
