/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:30:04 by ataftai           #+#    #+#             */
/*   Updated: 2017/11/01 20:09:48 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	usage_error(void)
{
	ft_putstr("USAGE: ./RTv1 sc/<scene>\n");
	exit(1);
}

void	mem_error(void)
{
	ft_putstr("Memory allocation error\n");
	exit(1);
}

void	f_error(void)
{
	ft_putstr("No such scene. Choose another one.\n");
	usage_error();
	exit(1);
}
