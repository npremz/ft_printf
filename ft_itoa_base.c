/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:12:55 by npremont          #+#    #+#             */
/*   Updated: 2023/10/19 18:31:25 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static char	*ft_putnbr_str(long int n, char *str, char *base, int pos)
{
	int			baselen;

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

static char	*ft_str_alloc(int n, int size)
{
	char	*str;

	if (n < 0)
	{
		str = malloc(size * sizeof(char) + 2);
		str[size + 1] = '\0';
	}
	else 
	{
		str = malloc(size * sizeof(char) + 1);
		str[size] = '\0';
	}
	return (str);
}

char	*ft_itoa_base(int n, char *base)
{
	char		*str;
	int			baselen;
	long int	og_nbr;
	int			i;
	long int	nbr;

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
	str = ft_putnbr_str(og_nbr, str, base, i - 1);
	return (str);
}
