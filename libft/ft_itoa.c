/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 23:22:20 by asuissa           #+#    #+#             */
/*   Updated: 2017/11/23 04:41:00 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_nb(long long tmp, int *neg)
{
	int i;

	*neg = 0;
	i = 0;
	if (tmp < 0)
	{
		tmp = -tmp;
		i++;
		*neg = 1;
	}
	while (tmp > 10)
	{
		tmp = tmp / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(long long n)
{
	int		t[2];
	char	*s;

	t[0] = nb_nb(n, &t[1]);
	if (!(s = (char *)malloc(sizeof(char) * t[0] + 2)))
		return (NULL);
	t[0] = 0;
	if (n < 0)
		n = -n;
	while (n || !t[0])
	{
		s[t[0]] = '0' + (n % 10);
		n = n / 10;
		t[0]++;
	}
	if (t[1])
	{
		s[t[0]] = '-';
		t[0]++;
	}
	s[t[0]] = '\0';
	s = ft_strrev((s));
	return (s);
}
