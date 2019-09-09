/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:07:04 by asuissa           #+#    #+#             */
/*   Updated: 2017/11/16 16:13:50 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*out;

	out = (char *)malloc(sizeof(char) * size + 1);
	if (!out)
		return (NULL);
	ft_bzero(out, size + 1);
	return (out);
}
