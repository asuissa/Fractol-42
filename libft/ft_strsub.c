/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:40:52 by asuissa           #+#    #+#             */
/*   Updated: 2017/11/16 17:54:13 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	int		i;

	if (!s)
		return (NULL);
	out = (char *)malloc(sizeof(char) * len + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (len)
	{
		out[i] = s[start];
		start++;
		len--;
		i++;
	}
	out[i] = '\0';
	return (out);
}
