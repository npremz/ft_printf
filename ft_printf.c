/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:39:30 by npremont          #+#    #+#             */
/*   Updated: 2023/10/20 14:38:40 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handlespec(const char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (c == 'p')
	{
		return (ft_printaddr(ft_lutoa_base(va_arg(arg, long int),
					"0123456789abcdef")));
	}
	if (c == 'd' || c == 'i')
		return (ft_printn(ft_itoa(va_arg(arg, int))));
	if (c == 'u')
		return (ft_printn(ft_utoa(va_arg(arg, int))));
	if (c == 'x')
		return (ft_printn(ft_utoa_base(va_arg(arg, int), "0123456789abcdef")));
	if (c == 'X')
		return (ft_printn(ft_utoa_base(va_arg(arg, int), "0123456789ABCDEF")));
	if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

static int	ft_handlestr(const char *input, va_list list, int count)
{
	int	i;
	int	rep;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			i++;
			rep = ft_handlespec(input[i++], list);
			if (rep == -1)
				return (-1);
			count += rep;
		}
		else
		{
			if (write(1, &input[i++], 1) == -1)
				return (-1);
			++count;
		}
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	va_list	list;
	int		count;

	i = 0;
	count = 0;
	va_start(list, input);
	count = ft_handlestr(input, list, count);
	va_end(list);
	return (count);
}
