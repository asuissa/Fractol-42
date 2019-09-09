/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:41:14 by asuissa           #+#    #+#             */
/*   Updated: 2018/01/09 00:22:50 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *tmp1;
	unsigned char *tmp2;
	unsigned char a;

	if (!dst || !src)
		return (NULL);
	a = (unsigned char)c;
	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	while (n)
	{
		*tmp1 = *tmp2;
		tmp1++;
		n--;
		if (*tmp2 == a)
			return (tmp1);
		tmp2++;
	}
	return (NULL);
}
