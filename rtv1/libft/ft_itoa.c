/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:37:34 by ataftai           #+#    #+#             */
/*   Updated: 2016/12/12 14:10:29 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(long num)
{
	int cnt;

	cnt = 1;
	if (num < 0)
		cnt++;
	while (num /= 10)
		cnt++;
	return (cnt);
}

static	void	writenum(char **str, long n)
{
	if (n >= 10)
	{
		writenum(str, n / 10);
		writenum(str, n % 10);
	}
	else
	{
		**str = n + '0';
		*(++(*str)) = '\0';
	}
}

char			*ft_itoa(int n)
{
	long long	num;
	char		*str;
	int			c;

	num = n;
	c = count(num);
	str = (char *)malloc(sizeof(char) * (c + 1));
	if (!str)
		return (0);
	if (num < 0)
	{
		*str = '-';
		str++;
		num *= -1;
	}
	writenum(&str, num);
	return (str - c);
}
