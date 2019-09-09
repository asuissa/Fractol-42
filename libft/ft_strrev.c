/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:29:48 by asuissa           #+#    #+#             */
/*   Updated: 2018/01/09 00:34:05 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		a;
	int		b;
	char	c;

	if (!str)
		return (NULL);
	b = ft_strlen(str) - 1;
	a = 0;
	while (a < b)
	{
		c = str[a];
		str[a] = str[b];
		str[b] = c;
		a++;
		b--;
	}
	return (str);
}
