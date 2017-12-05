/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:55:16 by ataftai           #+#    #+#             */
/*   Updated: 2016/12/12 14:08:26 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char *str;
	char *st;
	char *z;

	if (!s)
		return (0);
	st = (char *)s + ft_strlen(s) - 1;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (st >= s && (*st == ' ' || *st == '\n' || *st == '\t'))
		st--;
	if (!*s)
		str = (char *)malloc(sizeof(char) * 1);
	else
		str = (char *)malloc(sizeof(char) * (st - s + 2));
	if (!str)
		return (0);
	z = str;
	while (s <= st)
		*str++ = *s++;
	*str = '\0';
	return (z);
}
