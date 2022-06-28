/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:29:35 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/28 12:43:18 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	print_stack(t_list *lst)
{
	t_list	*p;

	if (!lst)
		return ;
	p = lst;
	while (p->next)
	{
		printf("%s\n", p->content);
		p = p->next;
	}
	return ;
}

void	print_stacks(t_list *lst_l, t_list *lst_r)
{
	t_list	*l;
	t_list	*r;

	l = lst_l;
	r = lst_r;
	while (l || r)
	{
		if (l && r)
		{
			printf("%s\t%s\n", l->content, r->content);
			l = l->next;
			r = r->next;
		}
		else if (l)
		{
			printf("%s\n", l->content);
			l = l->next;
		}
		else
		{
			printf("\t%s\n", r->content);
			r = r->next;
		}
	}
	printf("__\t__\n-------------------------------\n");
	return ;
}
