/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:29:42 by asuissa           #+#    #+#             */
/*   Updated: 2017/12/05 19:43:35 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoin(char **s1, char *s2)
{
	char	*out;

	if (!s1 || !s2)
		return (NULL);
	if (!(out = (char *)malloc((ft_strlen(*s1) + ft_strlen(s2) + 1))))
		return (NULL);
	*out = '\0';
	ft_strcat(out, *s1);
	out[ft_strlen(*s1)] = '\0';
	ft_strcat(out, s2);
	out[ft_strlen(*s1) + ft_strlen(s2)] = '\0';
	free(*s1);
	return (out);
}
