/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:51:11 by ataftai           #+#    #+#             */
/*   Updated: 2017/11/01 20:10:08 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

double	cone_int(t_t_h *rt, t_ob *temp, t_v r, t_v p)
{
	double ds;

	rt->dis = s_vect(&p, &temp->p);
	n_vect(&temp->r);
	rt->a0 = d_vect(&r, &r) - (1 + pow(tan(temp->size), 2))
		* pow(d_vect(&r, &temp->r), 2);
	rt->b0 = 2 * (d_vect(&r, &rt->dis) - (1 + pow(tan(temp->size), 2)) *
			d_vect(&r, &temp->r) * d_vect(&rt->dis, &temp->r));
	rt->c0 = d_vect(&rt->dis, &rt->dis) - (1 + pow(tan(temp->size), 2)) *
		pow(d_vect(&rt->dis, &temp->r), 2);
	ds = rt->b0 * rt->b0 - 4 * rt->a0 * rt->c0;
	if (ds < 0)
		return (-1);
	rt->t_0 = (-rt->b0 + sqrtf(ds)) / (2 * rt->a0);
	rt->t_1 = (-rt->b0 - sqrtf(ds)) / (2 * rt->a0);
	if (rt->t_1 < rt->t_0)
		rt->t_0 = rt->t_1;
	return (rt->t_0);
}

double	cyl_int(t_t_h *rt, t_ob *temp, t_v r, t_v p)
{
	double	ds;

	rt->dis = s_vect(&p, &temp->p);
	n_vect(&temp->r);
	rt->a0 = d_vect(&r, &r) - pow(d_vect(&r, &temp->r), 2);
	rt->b0 = 2 * (d_vect(&r, &rt->dis) - (d_vect(&r, &temp->r) *
			d_vect(&rt->dis, &temp->r)));
	rt->c0 = d_vect(&rt->dis, &rt->dis) - pow(d_vect(&rt->dis, &temp->r), 2)
		- pow(temp->size, 2);
	ds = rt->b0 * rt->b0 - 4 * rt->a0 * rt->c0;
	if (ds < 0)
		return (-1);
	rt->t_0 = (-rt->b0 + sqrtf(ds)) / (2 * rt->a0);
	rt->t_1 = (-rt->b0 - sqrtf(ds)) / (2 * rt->a0);
	if (rt->t_1 < rt->t_0)
		rt->t_0 = rt->t_1;
	return (rt->t_0);
}

double	pl_int(t_t_h *rt, t_ob *temp, t_v r, t_v p)
{
	rt->t_0 = ((d_vect(&temp->r, &temp->p) - d_vect(&temp->r, &p)) /
			d_vect(&temp->r, &r));
	return ((rt->t_0 < 0.0001) ? -1 : rt->t_0);
}

double	sp_int(t_t_h *rt, t_ob *temp, t_v r, t_v p)
{
	double ds;

	rt->dis = s_vect(&p, &temp->p);
	rt->a0 = d_vect(&r, &r);
	rt->b0 = 2 * d_vect(&r, &rt->dis);
	rt->c0 = d_vect(&rt->dis, &rt->dis) - (temp->size * temp->size);
	ds = rt->b0 * rt->b0 - 4 * rt->a0 * rt->c0;
	if (ds < 0)
		return (-1);
	rt->t_0 = (-rt->b0 + sqrtf(ds)) / (2 * rt->a0);
	rt->t_1 = (-rt->b0 - sqrtf(ds)) / (2 * rt->a0);
	if (rt->t_1 < rt->t_0)
		rt->t_0 = rt->t_1;
	return (rt->t_0);
}
