/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:37:52 by ataftai           #+#    #+#             */
/*   Updated: 2017/11/01 20:11:08 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		colnp(t_rt *rt, t_ob *o, int m)
{
	int	j;

	j = 6;
	if (ft_strncmp(rt->sc[m + 2], "		col(", 6) ||
			ft_strncmp(rt->sc[m + 3], "		pos(", 6))
		return (-1);
	o->col.r = nft_atoi(rt->sc[m + 2], &j);
	o->col.g = nft_atoi(rt->sc[m + 2], &j);
	o->col.b = nft_atoi(rt->sc[m + 2], &j);
	if (rt->sc[m + 2][j] != ')')
		return (-1);
	j = 6;
	o->p.x = nft_atoi(rt->sc[m + 3], &j);
	o->p.y = nft_atoi(rt->sc[m + 3], &j);
	o->p.z = nft_atoi(rt->sc[m + 3], &j);
	if (rt->sc[m + 3][j] != ')')
		return (-1);
	return (0);
}

int		check_o(t_rt *rt, t_ob *obj)
{
	obj = rt->l;
	while (obj)
	{
		if (!(obj->col.r >= 0 && obj->col.r <= 255) ||
			!(obj->col.g >= 0 && obj->col.g <= 255) ||
			!(obj->col.b >= 0 && obj->col.b <= 255))
			return (-1);
		obj = obj->next;
	}
	obj = rt->ob;
	while (obj)
	{
		if (!(obj->col.r >= 0 && obj->col.r <= 255) ||
			!(obj->col.g >= 0 && obj->col.g <= 255) ||
			!(obj->col.b >= 0 && obj->col.b <= 255))
			return (-1);
		if ((obj->tp == 2 || obj->tp == 4) && obj->size < 0)
			return (-1);
		obj = obj->next;
	}
	return (0);
}

int		check_s(t_rt *rt, int i)
{
	if (ft_strcmp(rt->sc[0], "scene") ||
			ft_strcmp(rt->sc[1], "{") ||
			ft_strcmp(rt->sc[4], "}") ||
			ft_strncmp(rt->sc[2], "	cam_pos(", 9))
		return (-1);
	rt->c_p.x = (double)nft_atoi(rt->sc[2], &i);
	rt->c_p.y = (double)nft_atoi(rt->sc[2], &i);
	rt->c_p.z = (double)nft_atoi(rt->sc[2], &i);
	if (ft_strncmp(rt->sc[3], "	cam_dir(", 9) ||
			(rt->sc[2][i] != ')'))
		return (-1);
	i = 9;
	rt->c_d.x = (double)nft_atoi(rt->sc[3], &i);
	rt->c_d.y = (double)nft_atoi(rt->sc[3], &i);
	rt->c_d.z = (double)nft_atoi(rt->sc[3], &i);
	if (rt->sc[3][i] != ')' ||
			(ft_strlen(rt->sc[5])))
		return (-1);
	return (0);
}

int		p_ob(t_rt *rt, int i)
{
	int	r;

	while (i < rt->n_l - 1)
	{
		if (!ft_strcmp(rt->sc[i], "	object(light)"))
			r = add_l(rt, &i, 6);
		else if (!ft_strcmp(rt->sc[i], "	object(cone)"))
			r = add_con(rt, &i, 1, 6);
		else if (!ft_strcmp(rt->sc[i], "	object(cylinder)"))
			r = add_con(rt, &i, 2, 6);
		else if (!ft_strcmp(rt->sc[i], "	object(plane)"))
			r = add_pl(rt, &i, 6);
		else if (!ft_strcmp(rt->sc[i], "	object(sphere)"))
			r = add_sp(rt, &i, 7);
		else
			return (del_l(rt->l, rt->ob));
	}
	return (0);
}

int		pars(t_rt *rt)
{
	if ((check_s(rt, 9) == -1) ||
			ft_strcmp(rt->sc[6], "content") ||
			ft_strcmp(rt->sc[7], "{") ||
			ft_strcmp(rt->sc[rt->n_l - 1], "}") ||
			(p_ob(rt, 8) == -1))
		return (-1);
	if (check_o(rt, 0) == -1)
	{
		ft_putstr("Incorrect value for color/size\n");
		return (-1);
	}
	return (0);
}
