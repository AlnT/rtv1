/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:06:04 by ataftai           #+#    #+#             */
/*   Updated: 2016/12/12 16:39:49 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t s;

	if (!src)
		return (0);
	s = ft_strlen(src);
	if (dst)
	{
		s = ft_strlen(src);
		while (*src && --size > 0)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (s);
}
