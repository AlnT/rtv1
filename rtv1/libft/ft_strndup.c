/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:52:49 by ataftai           #+#    #+#             */
/*   Updated: 2016/12/12 13:01:59 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	ind;

	ind = 0;
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (0);
	while (s1[ind] && n-- > 0)
	{
		str[ind] = s1[ind];
		ind++;
	}
	str[ind] = '\0';
	return (str);
}
