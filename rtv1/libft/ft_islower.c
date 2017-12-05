/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:33:15 by ataftai           #+#    #+#             */
/*   Updated: 2016/12/12 14:22:33 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_islower(int c)
{
	if (c >= 0 && c <= 255 && (unsigned char)c >= 'a'
			&& (unsigned char)c <= 'z')
		return (1);
	return (0);
}
