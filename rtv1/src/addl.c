/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:46:04 by ataftai           #+#    #+#             */
/*   Updated: 2017/11/01 20:09:23 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		del_l(t_ob *l, t_ob *t)
{
	t_ob *f;
	t_ob *temp;

	f = t;
	while (f)
	{
		temp = f->next;
		free(f);
		f = temp;
	}
	f = l;
	while (f)
	{
		temp = f->next;
		free(f);
		f = temp;
	}
	return (-1);
}

int		nft_atoi(char *str, int *i)
{
	int		f;
	int		ret;

	f = 1;
	while (str[*i] >= 0 && str[*i] <= 32)
		(*i)++;
	if (str[*i] == '-')
		f *= -1;
	if (str[*i] == '+' || str[*i] == '-')
		(*i)++;
	ret = 0;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		ret = ret * 10 + str[*i] - '0';
		(*i)++;
	}
	return (f * ret);
}

t_ob	*add_ll(t_rt *rt, t_ob *o)
{
	t_ob *h;

	h = rt->l;
	if (!rt->l)
		return (o);
	while (rt->l->next)
		rt->l = rt->l->next;
	rt->l->next = o;
	return (h);
}

t_ob	*add_ol(t_rt *rt, t_ob *o)
{
	t_ob *h;

	h = rt->ob;
	if (!rt->ob)
		return (o);
	while (rt->ob->next)
		rt->ob = rt->ob->next;
	rt->ob->next = o;
	return (h);
}
