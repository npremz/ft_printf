/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:39:30 by npremont          #+#    #+#             */
/*   Updated: 2023/10/19 18:31:51 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "libft/libft.h"

static int	ft_handlespec(const char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_printn(ft_litoa_base(va_arg(arg, long int),
					"0123456789abcdef")) + 2);
	}
	if (c == 'd' || c == 'i')
		return (ft_printn(ft_itoa_base(va_arg(arg, int), "0123456789")));
	if (c == 'u')
		return (ft_printn(ft_utoa(va_arg(arg, int))));
	if (c == 'x')
		return (ft_printn(ft_itoa_base(va_arg(arg, int), "0123456789abcdef")));
	if (c == 'X')
		return (ft_printn(ft_itoa_base(va_arg(arg, int), "0123456789ABCDEF")));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

static void	ft_handlestr(const char *input, va_list list, int *count)
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
				break ;
			*count += rep;
		}
		else
		{
			if (write(1, &input[i++], 1) == -1)
				break ;
			++*count;
		}
	}
}

int	ft_printf(const char *input, ...)
{
	int		i;
	va_list	list;
	int		count;

	i = 0;
	count = 0;
	va_start(list, input);
	ft_handlestr(input, list, &count);
	va_end(list);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("Mine:\n");
	ft_printf("Length printed : %d\n\n", ft_printf("Printf a char : %d. Done!\n", INT_MIN));
	ft_printf("Length printed : %i\n\n", ft_printf("Printf a char : %d. Done!\n", INT_MIN));

	printf("Og:\n");
	printf("Length printed : %d\n\n", printf("Printf a char : %d. Done!\n", INT_MAX));
	printf("Length printed : %i\n\n", printf("Printf a char : %d. Done!\n", INT_MAX));
	return (0);
}
