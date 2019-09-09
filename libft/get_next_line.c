/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 22:42:21 by asuissa           #+#    #+#             */
/*   Updated: 2018/01/10 06:28:23 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*init_lst(t_list **lst, size_t fd)
{
	t_list	*tmp;

	if (!*lst)
		if (!(*lst = ft_lstnew("\0", fd)))
			return (NULL);
	tmp = *lst;
	while (tmp->content_size != fd)
	{
		if (!tmp->next)
			if (!(tmp->next = ft_lstnew("\0", fd)))
				return (NULL);
		tmp = tmp->next;
	}
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	t_init_gnl		a;
	static	t_list	*lst = NULL;

	ft_bzero(&a, sizeof(t_init_gnl));
	if (fd < 0 || !line || BUFF_SIZE < 1 || (a.r = read(fd, a.buffer, 0)) < 0)
		return (-1);
	a.tmp = init_lst(&lst, (size_t)fd);
	a.c = (char *)a.tmp->content;
	while (!ft_strchr(a.c, '\n') && (a.r = read(fd, a.buffer, BUFF_SIZE)))
	{
		a.buffer[a.r] = '\0';
		if (!(a.c = ft_strfjoin(&a.c, a.buffer)))
			return (-1);
	}
	if (!*a.c && !(*line = NULL))
		return (0);
	a.b = ft_strclen(a.c, '\n');
	*line = ft_strncpy(ft_strnew(a.b + 1), a.c, a.b);
	if (ft_strlen(a.c) == ft_strclen(a.c, '\n'))
		a.tmp->content = ft_strdup((a.c + ft_strclen(a.c, '\n')));
	else
		a.tmp->content = ft_strdup((a.c + ft_strclen(a.c, '\n') + 1));
	free(a.c);
	return (1);
}
