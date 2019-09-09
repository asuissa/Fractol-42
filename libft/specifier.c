/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 02:00:28 by asuissa           #+#    #+#             */
/*   Updated: 2018/02/25 19:33:21 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** specifier "sSpdDioOuUxXcbyw"
*/

int		spec_s(va_list ap, char *out)
{
	char	*tmp;
	int		ret;
	char	*ftmp;

	ret = 0;
	tmp = va_arg(ap, char *);
	if ((ft_strlen(out) + ft_strlen(tmp)) > BUFF_SIZE)
	{
		ft_putstr((ftmp = del_pourcent(out)));
		ft_bzero(out, BUFF_SIZE + 1);
		ret = (int)ft_strlen(ftmp);
		free(ftmp);
	}
	ft_strcat(out, tmp);
	return (ret);
}

int		spec_p(va_list ap, char *out)
{
	char	*tmp;
	int		ret;
	char	*ftmp;

	ret = 0;
	tmp = ft_itoa_base((long long)va_arg(ap, void *), "0123456789abcdef");
	if ((ft_strlen(out) + ft_strlen(tmp)) > BUFF_SIZE)
	{
		ft_putstr((ftmp = del_pourcent(out)));
		ft_bzero(out, BUFF_SIZE + 1);
		ret = (int)ft_strlen(ftmp);
		free(ftmp);
	}
	ft_strcat(out, "0x");
	ft_strcat(out, tmp);
	free(tmp);
	return (ret);
}

int		spec_d(va_list ap, char *out)
{
	char	*tmp;
	int		ret;
	char	*ftmp;

	ret = 0;
	tmp = ft_itoa((long long)va_arg(ap, int));
	if ((ft_strlen(out) + ft_strlen(tmp)) > BUFF_SIZE)
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

int		spec_c(va_list ap, char *out)
{
	int		tmp;
	int		ret;
	char	*ftmp;

	ret = 0;
	tmp = va_arg(ap, int);
	if ((ft_strlen(out) + 1) > BUFF_SIZE)
	{
		ft_putstr((ftmp = del_pourcent(out)));
		ft_bzero(out, BUFF_SIZE + 1);
		ret = (int)ft_strlen(ftmp);
		free(ftmp);
	}
	ft_strcat(out, (char *)&tmp);
	return (ret);
}

int		spec_b(va_list ap, char *out)
{
	char	*tmp;
	int		ret;
	char	*ftmp;

	ret = 0;
	tmp = ft_itoa_base((long long)va_arg(ap, int), "01");
	if ((ft_strlen(out) + ft_strlen(tmp)) > BUFF_SIZE)
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
