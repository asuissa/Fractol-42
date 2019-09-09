/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 17:49:15 by asuissa           #+#    #+#             */
/*   Updated: 2018/02/25 19:42:36 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*out;
	int		a;

	a = 0;
	if (!format)
		return (-1);
	if ((a = nb_pourcent((char *)format)) > 0)
	{
		va_start(ap, format);
		a = real_job((char *)format, ap);
		va_end(ap);
	}
	else
	{
		ft_putstr((out = del_pourcent((char *)format)));
		a = (int)ft_strlen(out);
		free(out);
	}
	return (a);
}

char	*del_pourcent(char *str)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	j = 0;
	if (!(out = ft_strnew(ft_strlen(str))))
		return (NULL);
	while (str[i])
	{
		out[j] = str[i];
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		i++;
		j++;
	}
	return (out);
}

int		nb_pourcent(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
			j++;
		else if (str[i] == '%' && str[i + 1] == '%')
			i++;
		i++;
	}
	return (j);
}

int		real_job(char *str, va_list ap)
{
	static int	(*fct[])(va_list, char *) = {spec_s, spec_p, spec_d, spec_d,
		spec_c, spec_b, spec_y, spec_w, spec_o, spec_u, spec_x, spec_gx,
		spec_gc, spec_gs, NULL};
	char		*spec;
	char		out[BUFF_SIZE + 1];
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	ft_bzero(out, BUFF_SIZE);
	spec = "spdicbywouxXCS";
	while (str[i])
	{
		if (str[i] == '%' && ft_strnchr(spec, str[i + 1]))
		{
			ret = (fct[ft_strclen(spec, str[i + 1])])(ap, out);
			i++;
		}
		else
			ft_strncat(out, &str[i], 1);
		i++;
	}
	ft_putstr(out);
	return (ret + (int)ft_strlen(out));
}
