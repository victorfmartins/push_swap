/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:52:24 by vfranco-          #+#    #+#             */
/*   Updated: 2021/11/28 14:10:15 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*p;
	t_list	*p_next;

	if (!lst || !f)
		return ;
	p = lst;
	while (p)
	{
		p_next = p->next;
		f(p->content);
		p = p_next;
	}
}
