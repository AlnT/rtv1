/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:39:38 by ataftai           #+#    #+#             */
/*   Updated: 2017/11/01 20:09:38 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

char	*read_scene(t_rt *rt, char *file)
{
	int		fd;
	char	*s;
	char	*str;
	char	*temp;

	rt->n_l = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	s = ft_strnew(1);
	str = 0;
	while (get_next_line(fd, &str) > 0 && str)
	{
		temp = ft_strdup(s);
		free(s);
		s = ft_strjoin(temp, ft_strjoin(str, "\n"));
		free(temp);
		free(str);
		str = 0;
		rt->n_l++;
	}
	close(fd);
	return (s);
}

int		len_l(char *str, int i)
{
	int	j;

	j = 0;
	while (str && str[i] && str[i] != '\n')
	{
		i++;
		j++;
	}
	return (++j);
}

int		check(t_rt *rt, char *str)
{
	int	a;
	int	b;
	int	i;

	a = 0;
	i = 0;
	while (str && str[i] && a < rt->n_l)
	{
		b = 0;
		if (!(rt->sc[a] = (char *)malloc(sizeof(char) * len_l(str, i))))
			return (0);
		while (str[i] && str[i] != '\n')
			rt->sc[a][b++] = str[i++];
		rt->sc[a][b] = '\0';
		i++;
		a++;
	}
	return (1);
}

int		create_scene(t_rt *rt, char *file)
{
	char	*b;

	b = read_scene(rt, file);
	if (!b)
		return (0);
	if (!*b)
	{
		free(b);
		return (0);
	}
	if (!(rt->sc = (char **)malloc(sizeof(char *) * (rt->n_l + 1)))
			|| !check(rt, b))
	{
		free(b);
		mem_error();
	}
	free(b);
	return (1);
}

void	create_rt(char *file)
{
	t_rt *rt;

	if (!(rt = (t_rt *)malloc(sizeof(t_rt))))
		mem_error();
	if (!create_scene(rt, file))
	{
		free(rt);
		f_error();
	}
	rt->mlx = mlx_init();
	rt->win = mlx_new_window(rt->mlx, W_W, W_H, file);
	rt->img = mlx_new_image(rt->mlx, W_W, W_H);
	rt->data = mlx_get_data_addr(rt->img, &rt->bite, &rt->size,
			&rt->end);
	init(rt);
	if (pars(rt) == -1)
	{
		ft_putstr("Incorrect scene descriptor.\n");
		free(rt->sc);
		exit(1);
	}
	if (paint_rt(rt) == -1)
		exit(1);
	mlx_controle(rt);
}
