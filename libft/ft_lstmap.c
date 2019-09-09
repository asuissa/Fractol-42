/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 01:00:57 by asuissa           #+#    #+#             */
/*   Updated: 2017/11/27 19:58:28 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*out;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = (f(lst));
	out = tmp;
	while (lst->next)
	{
		(tmp->next) = (f(lst->next));
		tmp = tmp->next;
		lst = lst->next;
	}
	tmp->next = NULL;
	return (out);
}
