/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:37:27 by ataftai           #+#    #+#             */
/*   Updated: 2017/11/01 20:10:37 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

float	*reflect(t_t_h *rt, t_ob *temp, t_v *p, float *t)
{
	double	i;
	t_v		dst;
	t_ob	*l;
	t_ob	*temp2;
	int		flag;

	if (rt->cp >= rt->m_r || !(l = rt->l) ||
			!(temp2 = rinit(rt, temp, p)) || (rt->cp++) < 0)
		return (t);
	while (l)
	{
		t[3] = 0.14;
		dst = s_vect(&l->p, p);
		i = c_l(1.0 / sqrtf(sqrtf(d_vect(&dst, &dst))), 0.0, 1.0);
		n_vect(&dst);
		if (!shadow(rt, temp2, l, *p))
			t[3] += c_l(d_vect(&dst, &rt->nm), 0.0, 1.0);
		t = lend(temp2, l, t, i);
		flag = (rt->sp == 1 && temp2->tp != 3) ? 1 : 0;
		t[0] += (flag) ? spec(rt, dst, i, t[3]) : 0.0;
		t[1] += (flag) ? spec(rt, dst, i, t[3]) : 0.0;
		t[2] += (flag) ? spec(rt, dst, i, t[3]) : 0.0;
		l = l->next;
	}
	return ((rt->p_r == 1 && temp2->tp != 3) ? t : reflect(rt, temp2, p, t));
}

float	*lend(t_ob *temp, t_ob *l, float *t, float i)
{
	t[3] = c_l(t[3] * 4.0 * i, 0.0, 1.0);
	t[0] += t[3] * (temp->col.r / 255) * (l->col.r / 255);
	t[1] += t[3] * (temp->col.g / 255) * (l->col.g / 255);
	t[2] += t[3] * (temp->col.b / 255) * (l->col.b / 255);
	return (t);
}

float	spec(t_t_h *rt, t_v dst, float i, float l)
{
	t_v		r;
	float	temp;
	float	sp;

	sp = 0.0;
	r = scale_vect(&rt->nm, (2.0 * d_vect(&rt->nm, &dst)));
	r = s_vect(&dst, &r);
	if ((temp = d_vect(&r, &rt->r_d)) > 0.0 && l > 0.15)
	{
		sp = pow(temp, 20.0) * 4 * i;
		sp = c_l(sp, 0.0, 1.0);
	}
	return (sp);
}

int		shadow(t_t_h *rt, t_ob *temp, t_ob *l, t_v p)
{
	t_v		dst;
	t_ob	*el;

	el = rt->ob;
	dst = s_vect(&l->p, &p);
	rt->t = sqrtf(d_vect(&dst, &dst));
	n_vect(&dst);
	while (el)
	{
		if (el != temp)
		{
			if (el->tp == 1)
				rt->a0 = cone_int(rt, el, dst, p);
			if (el->tp == 2)
				rt->a0 = cyl_int(rt, el, dst, p);
			if (el->tp == 3)
				rt->a0 = pl_int(rt, el, dst, p);
			if (el->tp == 4)
				rt->a0 = sp_int(rt, el, dst, p);
			if (rt->a0 > 0.0001 && rt->a0 < rt->t)
				return (1);
		}
		el = el->next;
	}
	return (0);
}

t_v		norm(t_t_h *rt, t_ob *temp, t_v p)
{
	t_v	t1;
	t_v	t2;
	t_v	n;

	if (temp->tp == 2 || temp->tp == 1)
	{
		t1 = scale_vect(&temp->r, (d_vect(&rt->r_d, &temp->r) * rt->t_0 +
					d_vect(&rt->dis, &temp->r)));
		if (temp->tp == 1)
			t1 = scale_vect(&t1, (1 + pow(tan(temp->size), 2)));
		t2 = s_vect(&p, &temp->p);
		n = s_vect(&t2, &t1);
	}
	if (temp->tp == 3)
		n = temp->r;
	if (temp->tp == 4)
		n = s_vect(&p, &temp->p);
	n_vect(&n);
	return (n);
}
