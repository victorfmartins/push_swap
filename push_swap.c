/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:39:47 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/28 12:45:21 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	is_sorted(t_list *lst)
{
	t_list	*p;
	char	*max;

	if (!lst)
	{
		printf("is_sorted: list does not exist\n");
		return (1);
	}
	p = lst;
	max = p->content;
	while (p->next)
	{
		if (ft_strnbrcmp(max, p->content) <= 0)
			max = p->content;
		else
			return (0);
		p = p->next;
	}
	return (1);
}

void	ft_sort(t_list **lst_a, t_list **lst_b)
{
	if (lst_a == NULL || lst_b == NULL)
	{
		printf("ft_sorted: at least one list does not exist\n");
		return ;
	}
	while ((*lst_a))
	{
		if ((*lst_a)->next && ft_strnbrcmp((*lst_a)->content, (*lst_a)->next->content) > 0)
		{
			printf("sa\n");
			ft_lst_swap(lst_a);
		}
		else if ((*lst_b) == NULL || ft_strnbrcmp((*lst_a)->content, (*lst_b)->content) > 0)
		{
			printf("pb\n");
			ft_lst_push(lst_a, lst_b);
		}
		else
		{
			printf("pa\n");
			ft_lst_push(lst_b, lst_a);
		}
	}
	while ((*lst_b))
	{
		printf("pa\n");
		ft_lst_push(lst_b, lst_a);
	}
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_b = NULL;
	lst_a = NULL;
	build_stack_a(argc, argv, &lst_a);
	ft_sort(&lst_a, &lst_b);
	if (is_sorted(lst_a) == 0)
		printf("Stack is not sorted\n");
	// free stack with lstiter function
	return (0);
}
