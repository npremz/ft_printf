/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:44:10 by npremont          #+#    #+#             */
/*   Updated: 2023/10/20 12:35:50 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <limits.h>

/* FUNCTIONS */

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_printn(char *str);
int		ft_printaddr(char *str);
char	*ft_utoa_base(unsigned int nbr, char *base);
char	*ft_lutoa_base(unsigned long int nbr, char *base);
char	*ft_utoa(unsigned int n);
int		ft_printf(const char *input, ...);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
