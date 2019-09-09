/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:22:15 by asuissa           #+#    #+#             */
/*   Updated: 2018/01/09 00:20:49 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *tmp;

	if (!b)
		return (NULL);
	tmp = (unsigned char *)b;
	while (len)
	{
		*tmp = (unsigned char)c;
		tmp++;
		len--;
	}
	return (b);
}
