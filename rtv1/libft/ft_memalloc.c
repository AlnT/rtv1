/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:22:47 by ataftai           #+#    #+#             */
/*   Updated: 2016/12/02 15:32:58 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*st;
	size_t			i;

	i = 0;
	st = malloc(sizeof(st) * size);
	if (!st)
		return (0);
	while (i <= size)
		st[i++] = 0;
	return (st);
}
