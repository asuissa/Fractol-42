/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:26:30 by asuissa           #+#    #+#             */
/*   Updated: 2017/11/29 22:57:33 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

static int	nb_space(const char *s, size_t len)
{
	int	nb;

	nb = 0;
	while (is_separator(s[len - 1]) && len)
	{
		len--;
		nb++;
	}
	return (nb);
}

char		*ft_strtrim(char const *s)
{
	char	*out;
	size_t	len;
	int		nb;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	nb = nb_space(s, len);
	if (!(len - nb))
		return (ft_strdup("\0"));
	while (is_separator(*s) && *s)
	{
		s++;
		nb++;
	}
	out = (char *)malloc(sizeof(char) * (len - nb + 1));
	if (!out)
		return (NULL);
	out = ft_strncpy(out, s, (len - nb));
	out[len - nb] = '\0';
	return (out);
}
