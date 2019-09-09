/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 21:29:39 by asuissa           #+#    #+#             */
/*   Updated: 2018/02/25 19:31:30 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	int vers base
*/

int		spec_y(va_list ap, char *out)
{
	char	*tmp;
	int		ret;
	char	*ftmp;

	ret = 0;
	tmp = ft_itoa_base((long long)va_arg(ap, unsigned int), va_arg(ap, char *));
	if ((ft_strlen(out) + 1) > BUFF_SIZE)
	{
		ft_putstr((ftmp = del_pourcent(out)));
		ft_bzero(out, BUFF_SIZE + 1);
		ret = (int)ft_strlen(ftmp);
		free(ftmp);
	}
	ft_strcat(out, tmp);
	free(tmp);
	return (ret);
}

/*
**	base vers int
*/

int		spec_w(va_list ap, char *out)
{
	char	*tmp;
	int		ret;
	char	*ftmp;

	ret = 0;
	tmp = ft_itoa((long long)ft_atoi_base(va_arg(ap, char *),
				va_arg(ap, char *)));
	if ((ft_strlen(out) + 1) > BUFF_SIZE)
	{
		ft_putstr((ftmp = del_pourcent(out)));
		ft_bzero(out, BUFF_SIZE + 1);
		ret = (int)ft_strlen(ftmp);
		free(ftmp);
	}
	ft_strcat(out, tmp);
	free(tmp);
	return (ret);
}

int		spec_o(va_list ap, char *out)
{
	char	*tmp;
	int		ret;
	char	*ftmp;

	ret = 0;
	tmp = ft_itoa_base((long long)va_arg(ap, unsigned int), "01234567");
	if ((ft_strlen(out) + 1) > BUFF_SIZE)
	{
		ft_putstr((ftmp = del_pourcent(out)));
		ft_bzero(out, BUFF_SIZE + 1);
		ret = (int)ft_strlen(ftmp);
		free(ftmp);
	}
	ft_strcat(out, tmp);
	free(tmp);
	return (ret);
}

int		spec_u(va_list ap, char *out)
{
	char	*tmp;
	int		ret;
	char	*ftmp;

	ret = 0;
	tmp = ft_itoa((long long)va_arg(ap, unsigned int));
	if ((ft_strlen(out) + 1) > BUFF_SIZE)
	{
		ft_putstr((ftmp = del_pourcent(out)));
		ft_bzero(out, BUFF_SIZE + 1);
		ret = (int)ft_strlen(ftmp);
		free(ftmp);
	}
	ft_strcat(out, tmp);
	free(tmp);
	return (ret);
}

int		spec_x(va_list ap, char *out)
{
	char	*tmp;
	int		ret;
	char	*ftmp;

	ret = 0;
	tmp = ft_itoa_base((long long)va_arg(ap, unsigned int), "0123456789abcdef");
	if ((ft_strlen(out) + 1) > BUFF_SIZE)
	{
		ft_putstr((ftmp = del_pourcent(out)));
		ft_bzero(out, BUFF_SIZE + 1);
		ret = (int)ft_strlen(ftmp);
		free(ftmp);
	}
	ft_strcat(out, tmp);
	free(tmp);
	return (ret);
}
