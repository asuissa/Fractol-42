/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 21:21:09 by asuissa           #+#    #+#             */
/*   Updated: 2018/01/02 04:03:44 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	ft_strlowcase(str);
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	while (str[i] != '\0')
	{
		if (!(str[i] <= 'z' && str[i] >= 'a'))
			j = 1;
		if ((str[i] <= 'Z' && str[i] >= 'A')
				|| (str[i] <= '9' && str[i] >= '0'))
			j = 0;
		else if ((str[i] <= 'z' && str[i] >= 'a') && j == 1)
		{
			str[i] -= 32;
			j = 0;
		}
		i++;
	}
	return (str);
}
