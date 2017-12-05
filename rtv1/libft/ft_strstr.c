/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:30:18 by ataftai           #+#    #+#             */
/*   Updated: 2016/12/12 13:29:21 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;

	if (!*little)
		return ((char *)big);
	while (*big)
	{
		i = 0;
		if (*big == little[0])
		{
			while (little[i] && little[i] == *(big + i))
				i++;
			if (little[i] == '\0')
				return ((char *)big);
		}
		big++;
	}
	return (0);
}
