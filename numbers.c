/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:27:16 by npremont          #+#    #+#             */
/*   Updated: 2023/10/19 17:52:41 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printn(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (write(1, str, len) == -1)
		return (-1);
	free(str);
	return (len);
}
