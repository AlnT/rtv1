/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:18:15 by ataftai           #+#    #+#             */
/*   Updated: 2016/12/12 16:37:12 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char *sourc;

	dest = dst;
	sourc = src;
	while (n--)
	{
		if (*sourc == (unsigned char)c)
		{
			*dest = *sourc;
			return (++dest);
		}
		*dest++ = *sourc++;
	}
	return (0);
}
