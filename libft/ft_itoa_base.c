/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 22:41:51 by asuissa           #+#    #+#             */
/*   Updated: 2018/02/19 22:42:21 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_nb(long long tmp, int base)
{
	int	i;

	i = 0;
	if (tmp < 0)
	{
		tmp = -tmp;
		i++;
	}
	while (tmp)
	{
		tmp = tmp / base;
		i++;
	}
	return (i);
}

static void		ft_putnbrstr_base(long long n, char *base, char **out)
{
	int	a;

	a = (int)ft_strlen(base);
	if (n < 0)
	{
		(*out)[0] = '-';
		n = -n;
	}
	if (n / a)
	{
		ft_putnbrstr_base(n / a, base, out);
		ft_putnbrstr_base(n % a, base, out);
	}
	else
		*out = ft_strncat(*out, &base[n], 1);
}

char			*ft_itoa_base(long long nb, char *base)
{
	char	*out;

	if (!(out = ft_memalloc((nb_nb(nb, ft_strlen(base)) + 1))))
		return (NULL);
	ft_putnbrstr_base(nb, base, &out);
	return (out);
}
