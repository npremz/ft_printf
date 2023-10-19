/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:22:45 by npremont          #+#    #+#             */
/*   Updated: 2023/10/18 11:05:29 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char *str, char charsep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == charsep)
			++i;
		if (str[i] != '\0')
			++count;
		while (str[i] != '\0' && str[i] != charsep)
			++i;
	}
	return (count);
}

static void	*ft_free(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i] != 0)
	{
		free(tab[i]);
		++i;
	}
	free(tab);
	return (NULL);
}

static int	ft_stralloc(char *str, char charsep, char **str_tab)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == charsep)
			++i;
		while (str[i] != '\0' && str[i++] != charsep)
			++count;
		if (count > 0)
		{
			str_tab[j] = malloc(sizeof(char) * (count + 1));
			if (!str_tab[j])
				return (0);
			++j;
			count = 0;
		}
	}
	str_tab[j] = 0;
	return (1);
}

static void	ft_init(int *i, int *array_i, int *str_i)
{
	*i = 0;
	*array_i = 0;
	*str_i = 0;
}

char	**ft_split(char const *s, char charsep)
{
	char	**str_tab;
	int		i;
	int		array_i;
	int		str_i;
	char	*str;

	str = (char *)s;
	str_tab = (char **)malloc(sizeof(char *) * (ft_count(str, charsep) + 1));
	if (!str_tab || ft_stralloc(str, charsep, str_tab) == 0)
		return (ft_free(str_tab));
	ft_init(&i, &array_i, &str_i);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == charsep)
			++i;
		while (str[i] != '\0' && str[i] != charsep)
			str_tab[array_i][str_i++] = str[i++];
		if (str_tab[array_i] != 0)
		{
			str_tab[array_i++][str_i] = '\0';
			str_i = 0;
		}
	}
	return (str_tab);
}
