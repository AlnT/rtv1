/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:44:51 by ataftai           #+#    #+#             */
/*   Updated: 2017/11/01 20:09:58 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		result(char **line, char *buf_s)
{
	char	*r;

	r = ft_strchr(buf_s, '\n');
	if (r)
	{
		*r = '\0';
		*line = ft_strdup(buf_s);
		ft_memmove(buf_s, &r[1], ft_strlen(&r[1]) + 1);
		return (1);
	}
	if (ft_strlen(buf_s) > 0)
	{
		*line = ft_strdup(buf_s);
		*buf_s = '\0';
		return (1);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*buf_s = NULL;
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*str;

	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!buf_s)
		if (!(buf_s = (char *)malloc(sizeof(char))))
			return (-1);
	while (!ft_strchr(buf_s, '\n'))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (!ret)
			break ;
		buff[ret] = '\0';
		str = ft_strjoin(buf_s, buff);
		buf_s = ft_strdup(str);
		free(str);
	}
	return (result(line, buf_s));
}
