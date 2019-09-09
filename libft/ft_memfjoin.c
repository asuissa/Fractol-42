/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 23:07:02 by asuissa           #+#    #+#             */
/*   Updated: 2018/01/31 19:52:27 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memfjoin(void *s1, size_t ts1, void *s2, size_t ts2)
{
	void	*out;

	if (!s1 || !s2)
		return (NULL);
	if (!(out = malloc(ts1 + ts2)))
		return (NULL);
	ft_memcpy(out, s1, ts1);
	ft_memcpy(out + ts1, s2, ts2);
	free(s1);
	free(s2);
	return (out);
}
