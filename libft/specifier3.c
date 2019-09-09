/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 21:31:10 by asuissa           #+#    #+#             */
/*   Updated: 2018/02/25 19:53:11 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		spec_gx(va_list ap, char *out)
{
	char	*tmp;
	int		ret;
	char	*ftmp;

	ret = 0;
	tmp = ft_itoa_base((long long)va_arg(ap, unsigned int), "0123456789ABCDEF");
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

int		spec_gc(va_list ap, char *out)
{
	wchar_t	tmp[2];
	int		ret;
	char	*tmp2;
	char	*ftmp;

	tmp[0] = va_arg(ap, wchar_t);
	tmp[1] = '\0';
	ft_putstr((ftmp = del_pourcent(out)));
	ft_bzero(out, BUFF_SIZE + 1);
	ret = (int)ft_strlen(ftmp) + ft_wstrlen(tmp) + 1;
	free(ftmp);
	tmp2 = ft_transform_wchar(tmp);
	ft_putstr(tmp2);
	free(tmp2);
	return (ret);
}

int		spec_gs(va_list ap, char *out)
{
	wchar_t	*tmp;
	int		ret;
	char	*tmp2;
	char	*ftmp;

	tmp = va_arg(ap, wchar_t *);
	ft_putstr((ftmp = del_pourcent(out)));
	ft_bzero(out, BUFF_SIZE + 1);
	ret = (int)ft_strlen(ftmp) + ft_wstrlen(tmp);
	free(ftmp);
	tmp2 = ft_transform_wchar(tmp);
	ft_putstr(tmp2);
	free(tmp2);
	return (ret);
}
