/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:37:59 by asuissa           #+#    #+#             */
/*   Updated: 2017/12/12 22:38:05 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_array(const char *str, char sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == sep || str[i] == '\0')
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == sep && str[i + 1] != sep)
		{
			j++;
		}
		i++;
	}
	if (str[i - 1] == sep)
		j--;
	return (j + 2);
}

char		**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	k;
	int		fi;
	int		la;
	char	**tab;

	tab = NULL;
	i = 0;
	k = 0;
	if (s && (tab = (char **)malloc(sizeof(*tab) * (nb_array(s, c)))))
	{
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			fi = i;
			while (s[i] && s[i] != c)
				i++;
			la = i;
			if (la > fi)
				tab[k++] = ft_strsub(s, fi, (la - fi));
		}
		tab[k] = NULL;
	}
	return (tab);
}
