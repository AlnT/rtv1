/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:46:35 by ataftai           #+#    #+#             */
/*   Updated: 2016/12/12 13:29:35 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t c;
	size_t i;

	c = 0;
	if (!*little)
		return ((char *)&big[c]);
	while (big[c])
	{
		i = 0;
		while (big[c + i] == little[i] && little[i] && (c + i) < len)
			i++;
		if (little[i] == '\0')
			return ((char *)&big[c]);
		c++;
	}
	return (0);
}
