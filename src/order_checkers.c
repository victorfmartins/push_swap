/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 05:25:14 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/02 05:25:19 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_stack_ordered(t_list *stack)
{
	t_list	*ptr;

	ptr = stack;
	while (ptr && ptr->next)
	{
		if (get_stack_content(ptr) > get_stack_content(ptr->next))
			return (FALSE);
		ptr = ptr->next;
	}
	return (TRUE);
}

int	is_stack_ordered_by_n_elements(t_list *stack, int n)
{
	t_list	*ptr;
	int		i;

	ptr = stack;
	i = 1;
	while (ptr && ptr->next)
	{
		if ((i % n != 0)
			&& get_stack_content(ptr) > get_stack_content(ptr->next))
			return (FALSE);
		ptr = ptr->next;
		i++;
	}
	return (TRUE);
}

int	is_stack_ordered_until(t_list *stack, int ordered_until)
{
	t_list	*ptr;
	int		i;

	ptr = stack;
	i = 1;
	while (ptr && ptr->next && i < ordered_until)
	{
		if (get_stack_content(ptr) > get_stack_content(ptr->next))
			return (FALSE);
		ptr = ptr->next;
		i++;
	}
	return (TRUE);
}
