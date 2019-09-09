/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:58:24 by asuissa           #+#    #+#             */
/*   Updated: 2018/01/09 00:31:23 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	size_dst;

	if (!dst || !src)
		return (0);
	size_dst = ft_strlen(dst);
	j = 0;
	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	while (src[j] && (size_dst + j) < (size - 1))
	{
		dst[size_dst + j] = src[j];
		j++;
	}
	dst[size_dst + j] = '\0';
	if (size_dst < size)
		return (size_dst + ft_strlen(src));
	return (size + ft_strlen(src));
}
