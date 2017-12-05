/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:57:16 by ataftai           #+#    #+#             */
/*   Updated: 2017/11/01 20:11:17 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

t_ob	*intrs(t_t_h *rt, t_ob *el, t_v r, t_v p)
{
	double	d;
	t_ob	*temp;

	rt->t = 80000.0;
	temp = 0;
	while (el)
	{
		if (el->tp == 1)
			d = cone_int(rt, el, r, p);
		if (el->tp == 2)
			d = cyl_int(rt, el, r, p);
		if (el->tp == 3)
			d = pl_int(rt, el, r, p);
		if (el->tp == 4)
			d = sp_int(rt, el, r, p);
		if (d > 0.0001 && d < rt->t)
		{
			rt->t = d;
			temp = el;
		}
		el = el->next;
	}
	return (temp);
}

float	*avg(float *rm, float *t)
{
	rm[0] += c_l(t[0], 0.0, 1.0);
	rm[1] += c_l(t[1], 0.0, 1.0);
	rm[2] += c_l(t[2], 0.0, 1.0);
	return (rm);
}

float	*rayn(t_t_h *rt, float *t, double j, double i)
{
	double	a;
	double	b;

	b = (W_H - (double)i * 2.0) / W_W;
	a = (W_W - (double)j * 2.0) / W_H;
	rt->k = s_vect(&rt->c_d, &rt->c_p);
	n_vect(&rt->k);
	rt->i = cr_vect(&rt->k, &(t_v){0.0, 1.0, 0.0});
	n_vect(&rt->i);
	rt->j = cr_vect(&rt->i, &rt->k);
	rt->r_d = (t_v){a * rt->i.x + b * rt->j.x + 2.0 * rt->k.x,
		a * rt->i.y + b * rt->j.y + 2.0 * rt->k.y,
		a * rt->i.z + b * rt->j.z + 2.0 * rt->k.z};
	n_vect(&rt->r_d);
	rt->cp = 0;
	t[0] = 0.0;
	t[1] = 0.0;
	t[2] = 0.0;
	t[3] = 0.0;
	return (t);
}

float	*lmrt(t_t_h *rt, t_ob *temp, t_ob *l, float *t)
{
	float	i;
	t_v		p;
	t_v		dst;

	p = (t_v){rt->c_p.x + rt->t * rt->r_d.x, rt->c_p.y + rt->t *
		rt->r_d.y, rt->c_p.z + rt->t * rt->r_d.z};
	rt->nm = norm(rt, temp, p);
	while (l)
	{
		t[3] = 0.15;
		dst = s_vect(&l->p, &p);
		i = c_l((1.0 / sqrtf(sqrtf(d_vect(&dst, &dst)))), 0.0, 1.0);
		n_vect(&dst);
		if (!shadow(rt, temp, l, p))
			t[3] += c_l(d_vect(&dst, &rt->nm), 0.0, 1.0);
		t = lend(temp, l, t, i);
		t[0] += (rt->sp == 1 && temp->tp != 3) ? spec(rt, dst, i, t[3]) : 0.0;
		t[1] += (rt->sp == 1 && temp->tp != 3) ? spec(rt, dst, i, t[3]) : 0.0;
		t[2] += (rt->sp == 1 && temp->tp != 3) ? spec(rt, dst, i, t[3]) : 0.0;
		l = l->next;
	}
	rt->ref_p = (t_v){rt->r_d.x, rt->r_d.y, rt->r_d.z};
	return (((rt->p_r == 1 && temp->tp != 3) ? t : reflect(rt, temp, &p, t)));
}

int		rayt(t_t_h *rt, t_ob *el, double j, double i)
{
	float	rm[3];
	t_ob	*temp;
	float	*t;
	double	pt;

	fzer(rm, 3);
	if (!(t = (float *)malloc(sizeof(float) * 4)))
		return (-1);
	pt = 0.0;
	while (i < rt->t_y + 1 && (j = rt->t_x) > -1)
	{
		while (j < rt->t_x + 1 && (pt += 1) > 0)
		{
			rayn(rt, t, j, i);
			if ((temp = intrs(rt, el, rt->r_d, rt->c_p)))
				t = lmrt(rt, temp, rt->l, t);
			avg(rm, t);
			j = j + (1.0 / rt->a);
		}
		i = i + (1.0 / rt->a);
	}
	pixel_put(rt, rt->t_x, rt->t_y, (((int)(rm[0] / pt * 255) & 0xff) << 16) +
	(((int)(rm[1] / pt * 255) & 0xff) << 8) + ((int)(rm[2] / pt * 255) & 0xff));
	free(t);
	return (0);
}
