/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_alg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:37:50 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/03 13:38:42 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/small_alg_utils.h"

void	first_order_swap(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, NULL);
	if (*stack_b && (*stack_b)->next && get_stack_content(*stack_b)
		< get_stack_content((*stack_b)->next))
		swap(stack_b, "ss\n");
	else
		ft_printf("sa\n");
}

void	first_order_rotate(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b && get_stack_content(*stack_a)
		> get_stack_content(ft_lstlast(*stack_b))
		&& get_stack_content(*stack_a) < get_stack_content(*stack_b))
	{
		reverse_rotate(stack_b, "rrb\n");
		push(stack_a, stack_b, "pb\n");
		rotate(stack_b, "rb\n");
		rotate(stack_b, "rb\n");
	}
	else
		push(stack_a, stack_b, "pb\n");
}

void	second_order_push_and_swap(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a, "pa\n");
	swap(stack_a, NULL);
	if (*stack_b && (*stack_b)->next && get_stack_content(*stack_b)
		< get_stack_content((*stack_b)->next))
		swap(stack_b, "ss\n");
	else
		ft_printf("sa\n");
}
