/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:26:17 by ataftai           #+#    #+#             */
/*   Updated: 2016/12/12 16:39:21 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dest;
	const char	*source;
	size_t		siz;
	size_t		len;

	dest = dst;
	source = src;
	siz = size;
	while (*dest && siz-- != 0)
		dest++;
	len = dest - dst;
	siz = size - len;
	if (siz == 0)
		return (len + ft_strlen(source));
	while (*source)
	{
		if (siz != 1)
		{
			*dest++ = *source;
			siz--;
		}
		source++;
	}
	*dest = '\0';
	return (len + (source - src));
}
