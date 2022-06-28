/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:24:26 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/28 12:47:22 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_lst_swap(t_list **lst)
{
	void	*aux;

	aux = NULL;
	if (lst == NULL || (*lst) == NULL || (*lst)->next == NULL)
	{
		printf("lstsize not apropriated for swap\n");
		return ;
	}
	aux = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = aux;
	return ;
}

void	ft_lst_push(t_list **lst_from, t_list **lst_to)
{
	t_list	*aux;

	aux = NULL;
	if (lst_from == NULL || lst_to == NULL || (*lst_from) == NULL)
	{
		printf("Error with push\n");
		return ;
	}
	aux = (*lst_from)->next;
	ft_lstadd_front(lst_to, (*lst_from));
	*lst_from = aux;
	return ;
}
