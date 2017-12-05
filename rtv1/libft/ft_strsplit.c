/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:47:05 by ataftai           #+#    #+#             */
/*   Updated: 2016/12/12 15:31:44 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			count(char *str, char c)
{
	int		x;
	char	*s;

	x = 0;
	while (*str)
	{
		s = str;
		while (*str && *str != c)
			str++;
		if (str != s)
			x++;
		if (*str)
			str++;
	}
	return (x);
}

static	size_t		count_w(char *str, char c)
{
	size_t x;

	x = 0;
	while (*str && *str != c)
	{
		x++;
		str++;
	}
	return (x);
}

char				**ft_strsplit(char const *s, char c)
{
	int		y;
	size_t	x;
	char	**str;

	y = 0;
	if (!s)
		return (0);
	str = (char **)malloc(sizeof(str) * (count((char *)s, c) + 1));
	if (!str)
		return (0);
	while (*s)
	{
		if (*s && *s != c)
		{
			x = 0;
			str[y] = (char *)malloc(sizeof(char) * (count_w((char *)s, c) + 1));
			while (*s && *s != c)
				str[y][x++] = *s++;
			str[y++][x] = '\0';
		}
		if (*s)
			s++;
	}
	str[y] = 0;
	return (str);
}
