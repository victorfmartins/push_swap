/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 01:52:12 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/03 03:56:26 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/large_alg.h"

void	divide_with_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	size_stack_a;
	int	i;

	i = 0;
	size_stack_a = ft_lstsize(*stack_a);
	while (i < size_stack_a / 2)
	{
		push(stack_a, stack_b, "pb\n");
		i++;
	}
}

static void	first_order(t_list **stack_a, t_list **stack_b, t_counts *counts)
{
	int	max_elem_to_op_a;
	int	max_elem_to_op_b;

	max_elem_to_op_a = max_elem_to_op(*stack_a, BATCH_SIZE, counts->count_n_a);
	max_elem_to_op_b = max_elem_to_op(*stack_b, BATCH_SIZE, counts->count_n_b);
	while (!is_stack_ordered_until(*stack_a, max_elem_to_op_a)
		|| !is_stack_ordered_until(*stack_b, max_elem_to_op_b))
	{
		if (is_stack_ordered_until(*stack_a, max_elem_to_op_a))
			order_tree_elements(NULL, stack_b);
		else if (is_stack_ordered_until(*stack_b, max_elem_to_op_b))
			order_tree_elements(stack_a, NULL);
		else
			order_tree_elements(stack_a, stack_b);
	}
	merge_stacks(stack_a, stack_b, BATCH_SIZE * ft_power(2, 0), counts);
}

static void	second_order(t_list **stack_a, t_list **stack_b, int i)
{
	t_counts	counts;

	counts.na_case = TRUE;
	counts.count_n_a = 0;
	counts.count_n_b = 0;
	while (!is_stack_ordered_by_n_elements(*stack_a,
			BATCH_SIZE * ft_power(2, i + 1))
		|| !is_stack_ordered_by_n_elements(*stack_b,
			BATCH_SIZE * ft_power(2, i + 1))
		|| (ft_lstsize(*stack_a)
			< BATCH_SIZE * ft_power(2, i + 1) && *stack_b))
	{
		merge_stacks(stack_a, stack_b, BATCH_SIZE * ft_power(2, i), &counts);
	}
}

void	order_large_list(t_list **stack_a, t_list **stack_b)
{
	t_counts	counts;
	int			i;

	counts.na_case = TRUE;
	counts.count_n_a = 0;
	counts.count_n_b = 0;
	if (!is_stack_ordered(*stack_a))
		divide_with_stack_b(stack_a, stack_b);
	while (!is_stack_ordered_by_n_elements(*stack_a, BATCH_SIZE)
		|| !is_stack_ordered_by_n_elements(*stack_b, BATCH_SIZE))
		first_order(stack_a, stack_b, &counts);
	i = 1;
	while (!is_stack_ordered(*stack_a) || *stack_b)
	{
		second_order(stack_a, stack_b, i);
		i++;
	}
}
