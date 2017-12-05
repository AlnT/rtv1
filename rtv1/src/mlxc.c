/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 20:29:26 by ataftai           #+#    #+#             */
/*   Updated: 2017/11/01 20:10:26 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		chook(t_rt *rt)
{
	del_l(rt->l, rt->ob);
	mlx_destroy_image(rt->mlx, rt->img);
	mlx_destroy_window(rt->mlx, rt->win);
	free(rt->sc);
	free(rt);
	exit(1);
	return (0);
}

int		khook(int code, t_rt *rt)
{
	if (code == 53)
		chook(rt);
	if (code == 5)
	{
		rt->sp = (rt->sp == 0) ? 1 : 0;
		paint_rt(rt);
	}
	return (0);
}

void	mlx_controle(t_rt *rt)
{
	paint_rt(rt);
	mlx_hook(rt->win, 17, (1L << 17), chook, rt);
	mlx_hook(rt->win, 2, 1L << 0, khook, rt);
	mlx_loop(rt->mlx);
}
