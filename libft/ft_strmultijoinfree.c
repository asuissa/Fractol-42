/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmultijoinfree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 23:10:04 by asuissa           #+#    #+#             */
/*   Updated: 2018/01/10 06:24:59 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmultijoinfree(unsigned int nb, ...)
{
	char			*out;
	va_list			ap;

	if (!nb)
		return (NULL);
	out = ft_strnew(1);
	va_start(ap, nb);
	while (nb)
	{
		if (!(out = ft_strf2join(out, va_arg(ap, char *))))
			return (NULL);
		nb--;
	}
	va_end(ap);
	return (out);
}
