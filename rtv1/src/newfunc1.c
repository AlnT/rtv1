/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newfunc1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:32:45 by ataftai           #+#    #+#             */
/*   Updated: 2017/11/01 20:10:48 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	fzer(float *m, int i)
{
	int j;

	j = -1;
	while (++j < i)
		m[j] = 0.0f;
}

t_ob	*r_int(t_t_h *rt, t_ob *el, t_ob *temp, t_v p)
{
	double	dst;
	t_ob	*temp2;

	temp2 = 0;
	while (el)
	{
		if (el != temp)
		{
			if (el->tp == 1)
				dst = cone_int(rt, el, rt->ref, p);
			if (el->tp == 2)
				dst = cyl_int(rt, el, rt->ref, p);
			if (el->tp == 3)
				dst = pl_int(rt, el, rt->ref, p);
			if (el->tp == 4)
				dst = sp_int(rt, el, rt->ref, p);
			if (dst > 0.0001 && dst < rt->t)
			{
				temp2 = el;
				rt->t = dst;
			}
		}
		el = el->next;
	}
	return (temp2);
}

t_ob	*rinit(t_t_h *rt, t_ob *temp, t_v *p)
{
	t_ob	*temp2;

	rt->t = 8000.0;
	rt->ref = scale_vect(&rt->nm, (2 * d_vect(&rt->ref_p, &rt->nm)));
	rt->ref = s_vect(&rt->ref_p, &rt->ref);
	n_vect(&rt->ref);
	temp2 = r_int(rt, rt->ob, temp, *p);
	if (!temp2)
		return (0);
	*p = (t_v){p->x + rt->t * rt->ref.x, p->y + rt->t * rt->ref.y,
		p->z + rt->t * rt->ref.z};
	rt->ref_p = (t_v){rt->ref.x, rt->ref.y, rt->ref.z};
	rt->nm = norm(rt, temp2, *p);
	return (temp2);
}
