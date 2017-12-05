/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 20:32:14 by ataftai           #+#    #+#             */
/*   Updated: 2017/11/01 20:10:59 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	copy(t_rt *rt, t_t_h *t)
{
	t->data = rt->data;
	t->a = rt->a;
	t->size = rt->size;
	t->bite = rt->bite;
	t->ob = ob_cpy(rt->ob);
	t->l = ob_cpy(rt->l);
	t->cp = 0;
	t->sp = rt->sp;
	t->m_r = rt->m_r;
	t->p_r = rt->p_r;
	t->c_p = (t_v){rt->c_p.x, rt->c_p.y, rt->c_p.z};
	t->c_d = (t_v){rt->c_d.x, rt->c_d.y, rt->c_d.z};
	t->r_d = (t_v){rt->r_d.x, rt->r_d.y, rt->r_d.z};
}

t_ob	*ob_cpy(t_ob *ob)
{
	t_ob *fir;

	if (!(fir = (t_ob *)malloc(sizeof(t_ob))))
		return (0);
	if (!(ob && fir))
		return (0);
	fir->size = ob->size;
	fir->p = (t_v){ob->p.x, ob->p.y, ob->p.z};
	fir->r = (t_v){ob->r.x, ob->r.y, ob->r.z};
	fir->col.r = ob->col.r;
	fir->col.g = ob->col.g;
	fir->col.b = ob->col.b;
	fir->tp = ob->tp;
	fir->next = 0;
	if (fir && ob->next)
		fir->next = ob_cpy(ob->next);
	return (fir);
}

void	*t_p(void *a)
{
	double	i;
	double	j;
	t_tab	*t;
	t_t_h	*t_h;
	t_ob	*el;

	t_h = (t_t_h *)malloc(sizeof(t_t_h));
	t = (t_tab *)a;
	el = t->rt->ob;
	copy(t->rt, t_h);
	i = 0.0;
	while (i < W_H)
	{
		j = W_W * t->in / THR;
		while (j < W_W * (t->in + 1) / THR)
		{
			t_h->t_x = (int)j;
			t_h->t_y = (int)i;
			rayt(t_h, el, j++, i);
		}
		i++;
	}
	del_l(t_h->l, t_h->ob);
	free(t_h);
	pthread_exit(0);
}

int		paint_rt(t_rt *rt)
{
	void		*r;
	t_tab		tb[THR];
	pthread_t	t[THR];
	int			i;

	mlx_destroy_image(rt->mlx, rt->img);
	mlx_clear_window(rt->mlx, rt->win);
	rt->img = mlx_new_image(rt->mlx, W_W, W_H);
	i = 0;
	while (i < THR)
	{
		tb[i].in = i;
		tb[i].rt = rt;
		pthread_create(&t[i], 0, t_p, &tb[i]);
		i++;
	}
	i = 0;
	while (i < THR)
	{
		(void)pthread_join(t[i], &r);
		i++;
	}
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img, 0, 0);
	return (0);
}
