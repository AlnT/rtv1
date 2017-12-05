/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:28:42 by ataftai           #+#    #+#             */
/*   Updated: 2017/11/01 20:10:16 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	pixel_put(t_t_h *rt, int j, int i, int col)
{
	unsigned int	pt;
	int				a;

	a = 0;
	pt = j * (rt->bite / 8) + i * (rt->size);
	while (a < (rt->bite / 8))
	{
		rt->data[pt + a] = col;
		col >>= 8;
		a++;
	}
}

float	c_l(float v, float mn, float mx)
{
	if (v > mx)
		v = mx;
	if (v < mn)
		v = mn;
	return (v);
}

void	init(t_rt *rt)
{
	rt->a = 1;
	rt->p_r = 0;
	rt->m_r = 0;
	rt->sp = 0;
	rt->sel = 0;
	rt->h = 1;
	rt->l = 0;
	rt->ob = 0;
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		usage_error();
	create_rt(argv[1]);
	return (0);
}
