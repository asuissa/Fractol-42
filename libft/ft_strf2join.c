/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf2join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 23:21:22 by asuissa           #+#    #+#             */
/*   Updated: 2018/01/10 00:02:22 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strf2join(char *s1, char *s2)
{
	char	*out;

	if (!s1 || !s2)
		return (NULL);
	if (!(out = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	*out = '\0';
	ft_strcat(out, s1);
	out[ft_strlen(s1)] = '\0';
	ft_strcat(out, s2);
	out[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	free(s2);
	return (out);
}
