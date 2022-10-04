/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:55:47 by vfranco-          #+#    #+#             */
/*   Updated: 2021/11/28 14:10:21 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapi;
	t_list	*p;
	t_list	*p_next;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	mapi = NULL;
	p = lst;
	while (p)
	{
		p_next = p->next;
		temp = ft_lstnew(f(p->content));
		if (!temp)
		{
			ft_lstclear(&mapi, del);
			return (NULL);
		}
		ft_lstadd_back(&mapi, temp);
		p = p_next;
	}
	return (mapi);
}
