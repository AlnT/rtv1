/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:24:34 by ataftai           #+#    #+#             */
/*   Updated: 2017/11/01 20:11:27 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

t_v		s_vect(t_v *f, t_v *l)
{
	t_v s;

	s.x = f->x - l->x;
	s.y = f->y - l->y;
	s.z = f->z - l->z;
	return (s);
}

void	n_vect(t_v *f)
{
	double	r;

	r = 1.0 / sqrt(f->x * f->x + f->y * f->y +
			f->z * f->z);
	f->x *= r;
	f->y *= r;
	f->z *= r;
}

t_v		cr_vect(t_v *f, t_v *l)
{
	t_v	r;

	r.x = f->y * l->z - f->z * l->y;
	r.y = f->z * l->x - f->x * l->z;
	r.z = f->x * l->y - f->y * l->x;
	return (r);
}

t_v		scale_vect(t_v *f, float i)
{
	t_v ret;

	ret.x = f->x * i;
	ret.y = f->y * i;
	ret.z = f->z * i;
	return (ret);
}

float	d_vect(t_v *f, t_v *l)
{
	return (f->x * l->x + f->y * l->y + f->z * l->z);
}
