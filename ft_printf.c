/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:39:30 by npremont          #+#    #+#             */
/*   Updated: 2023/10/18 23:45:09 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_handlespec(const char c, va_list arg)
{
	if (c == 'c')
	{
		ft_putchar(va_arg(arg, int));
		return (1);
	}
	return (0);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	va_list	list;

	i = 0;
	va_start(list, input);
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			i++;
			ft_handlespec(input[i++], list);
		}
		else
			write(1, &input[i++], 1);
	}
	va_end(list);
}

int	main(void)
{
	ft_printf("Printf a char : %c. Done!\n", '8');
	return (0);
}
