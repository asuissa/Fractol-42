/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wortab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 23:35:39 by asuissa           #+#    #+#             */
/*   Updated: 2017/07/24 23:51:11 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_wordtab(char **tab)
{
	int		a;
	int		i;
	char	*b;

	a = 0;
	while (tab[a] != 0)
	{
		i = 0;
		while (tab[i] != 0)
		{
			if (ft_strcmp(tab[a], tab[i]) < 0)
			{
				b = tab[i];
				tab[i] = tab[a];
				tab[a] = b;
			}
			i++;
		}
		a++;
	}
}
