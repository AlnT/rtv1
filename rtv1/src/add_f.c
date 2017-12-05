/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:09:37 by ataftai           #+#    #+#             */
/*   Updated: 2017/11/01 20:09:11 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		add_l(t_rt *rt, int *m, int i)
{
	t_ob	*o;

	if (!(o = (t_ob *)malloc(sizeof(t_ob))) ||
			ft_strcmp(rt->sc[*m + 1], "	{") ||
			ft_strcmp(rt->sc[*m + 4], "	}") ||
			ft_strncmp(rt->sc[*m + 2], "		col(", 6) ||
			ft_strncmp(rt->sc[*m + 3], "		pos(", 6))
		return (-1);
	o->col.r = nft_atoi(rt->sc[*m + 2], &i);
	o->col.g = nft_atoi(rt->sc[*m + 2], &i);
	o->col.b = nft_atoi(rt->sc[*m + 2], &i);
	if (rt->sc[*m + 2][i] != ')')
		return (-1);
	i = 6;
	o->p.x = nft_atoi(rt->sc[*m + 3], &i);
	o->p.y = nft_atoi(rt->sc[*m + 3], &i);
	o->p.z = nft_atoi(rt->sc[*m + 3], &i);
	if (rt->sc[*m + 3][i] != ')')
		return (-1);
	o->next = 0;
	rt->l = add_ll(rt, o);
	*m += 5;
	return (0);
}

int		add_pl(t_rt *rt, int *m, int i)
{
	t_ob	*o;

	if (!(o = (t_ob *)malloc(sizeof(t_ob))))
		return (-1);
	o->tp = 3;
	if (ft_strcmp(rt->sc[*m + 1], "	{") ||
			ft_strcmp(rt->sc[*m + 5], "	}") ||
			colnp(rt, o, *m) == -1 ||
			ft_strncmp(rt->sc[*m + 4], "		rot(", 6))
		return (-1);
	o->r.x = (double)nft_atoi(rt->sc[*m + 4], &i);
	o->r.y = (double)nft_atoi(rt->sc[*m + 4], &i);
	o->r.z = (double)nft_atoi(rt->sc[*m + 4], &i);
	if (rt->sc[*m + 4][i] != ')')
		return (-1);
	o->next = 0;
	rt->ob = add_ol(rt, o);
	*m += 6;
	return (0);
}

int		add_con(t_rt *rt, int *m, int n, int i)
{
	t_ob	*o;

	if (!(o = (t_ob *)malloc(sizeof(t_ob))) ||
			ft_strcmp(rt->sc[*m + 1], "	{") ||
			ft_strcmp(rt->sc[*m + 6], "	}") ||
			(o->tp = n) != n ||
			(colnp(rt, o, *m) == -1) ||
			ft_strncmp(rt->sc[*m + 4], "		rot(", 6))
		return (-1);
	o->r.x = (double)nft_atoi(rt->sc[*m + 4], &i);
	o->r.y = (double)nft_atoi(rt->sc[*m + 4], &i);
	o->r.z = (double)nft_atoi(rt->sc[*m + 4], &i);
	if (rt->sc[*m + 4][i] != ')' ||
			ft_strncmp(rt->sc[*m + 5], "		size(", 7))
		return (-1);
	i = 7;
	o->size = nft_atoi(rt->sc[*m + 5], &i);
	if (rt->sc[*m + 5][i] != ')')
		return (-1);
	o->next = 0;
	rt->ob = add_ol(rt, o);
	*m += 7;
	return (0);
}

int		add_sp(t_rt *rt, int *m, int i)
{
	t_ob	*o;

	if (!(o = (t_ob *)malloc(sizeof(t_ob))))
		return (-1);
	o->tp = 4;
	if (ft_strcmp(rt->sc[*m + 1], "	{") ||
			ft_strcmp(rt->sc[*m + 5], "	}") ||
			colnp(rt, o, *m) == -1 ||
			ft_strncmp(rt->sc[*m + 4], "		size(", 7))
		return (-1);
	o->size = nft_atoi(rt->sc[*m + 4], &i);
	if (rt->sc[*m + 4][i] != ')')
		return (-1);
	o->next = NULL;
	rt->ob = add_ol(rt, o);
	*m += 6;
	return (0);
}
