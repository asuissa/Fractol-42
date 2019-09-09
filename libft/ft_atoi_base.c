/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 21:43:25 by asuissa           #+#    #+#             */
/*   Updated: 2018/02/18 22:33:12 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atoi_base(char *str, char *base)
{
	int			i;
	long long	val;
	int			n;

	if (!str)
		return (0);
	val = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	n = i;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_strchr(base, str[i]) && str[i])
	{
		val = val * ft_strlen(base) + (ft_strclen(base, str[i]));
		i++;
	}
	if (str[n] == '-')
		val = -val;
	return (val);
}
