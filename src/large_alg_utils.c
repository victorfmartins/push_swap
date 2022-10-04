/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_alg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 01:52:12 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/03 03:29:57 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/large_alg_utils.h"

void	rotate_swap_reverse(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, NULL);
	swap(stack_a, NULL);
	reverse_rotate(stack_a, NULL);
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		rotate(stack_b, "rr\n");
		swap(stack_b, "ss\n");
		reverse_rotate(stack_b, "rrr\n");
	}
	else
		ft_printf("ra\nsa\nrra\n");
}

void	order_tree_elements(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next
		&& first_is_greater_than_next(*stack_a))
	{
		swap(stack_a, NULL);
		if (stack_b && *stack_b && (*stack_b)->next
			&& first_is_greater_than_next(*stack_b))
			swap(stack_b, "ss\n");
		else
			ft_printf("sa\n");
	}
	else if (stack_b && *stack_b && (*stack_b)->next
		&& first_is_greater_than_next(*stack_b))
		swap(stack_b, "sb\n");
	else if (stack_a && *stack_a && (*stack_a)->next)
		rotate_swap_reverse(stack_a, stack_b);
	else if (stack_b && *stack_b && (*stack_b)->next)
	{
		rotate(stack_b, "rb\n");
		swap(stack_b, "sb\n");
		reverse_rotate(stack_b, "rrb\n");
	}
}

int	max_elem_to_op(t_list *stack, int batch_case, int count_n)
{
	int	size_stack;

	size_stack = ft_lstsize(stack);
	return (min(batch_case, size_stack - (2 * count_n * batch_case)));
}
