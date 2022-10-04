/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_merger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 05:25:28 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/03 04:17:24 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	merge_elements_at_a(t_list **stack_a, t_list **stack_b,
	t_elements *elements)
{
	int	max_element_to_push;
	int	max_element_to_end;

	max_element_to_end = elements->max_elem_to_op_a;
	max_element_to_push = elements->max_elem_to_op_b;
	if (*stack_a && *stack_b && get_stack_content(*stack_a)
		< get_stack_content(*stack_b)
		&& elements->element_to_end < max_element_to_end)
	{
		rotate(stack_a, "ra\n");
		(elements->element_to_end)++;
	}
	else if (*stack_b && elements->element_pushed < max_element_to_push)
	{
		push(stack_b, stack_a, "pa\n");
		rotate(stack_a, "ra\n");
		(elements->element_pushed)++;
	}
	else if (elements->element_to_end < max_element_to_end)
	{
		rotate(stack_a, "ra\n");
		(elements->element_to_end)++;
	}
}

void	merge_elements_at_b(t_list **stack_a, t_list **stack_b,
	t_elements *elements)
{
	int	max_element_to_push;
	int	max_element_to_end;

	max_element_to_end = elements->max_elem_to_op_b;
	max_element_to_push = elements->max_elem_to_op_a;
	if (*stack_a && *stack_b && get_stack_content(*stack_a)
		> get_stack_content(*stack_b)
		&& elements->element_to_end < max_element_to_end)
	{
		rotate(stack_b, "rb\n");
		(elements->element_to_end)++;
	}
	else if (*stack_a && elements->element_pushed < max_element_to_push)
	{
		push(stack_a, stack_b, "pb\n");
		rotate(stack_b, "rb\n");
		(elements->element_pushed)++;
	}
	else if (elements->element_to_end < max_element_to_end)
	{
		rotate(stack_b, "rb\n");
		(elements->element_to_end)++;
	}
}

void	update_counts(t_counts *counts)
{
	if (counts->na_case)
	{
		counts->count_n_a += 1;
		counts->na_case = FALSE;
	}
	else
	{
		counts->count_n_b += 1;
		counts->na_case = TRUE;
	}
}

void	push_from_a(t_list **stack_a, t_list **stack_b, int *max_elem_to_op_a)
{
	push(stack_a, stack_b, "pb\n");
	(*max_elem_to_op_a)--;
	while (*max_elem_to_op_a > 0)
	{
		push(stack_a, stack_b, "pb\n");
		rotate(stack_b, "rb\n");
		(*max_elem_to_op_a)--;
	}
}

void	merge_stacks(t_list **stack_a, t_list **stack_b, int batch_case,
	t_counts *counts)
{
	t_elements	elements;

	elements.element_pushed = 0;
	elements.element_to_end = 0;
	elements.max_elem_to_op_a
		= max_elem_to_op(*stack_a, batch_case, counts->count_n_a);
	elements.max_elem_to_op_b
		= max_elem_to_op(*stack_b, batch_case, counts->count_n_b);
	if (!*stack_b && !is_stack_ordered(*stack_a)
		&& elements.max_elem_to_op_a > 0)
		push_from_a(stack_a, stack_b, &(elements.max_elem_to_op_a));
	else if (counts->na_case)
		while (elements.element_to_end < elements.max_elem_to_op_a
			|| elements.element_pushed < elements.max_elem_to_op_b)
			merge_elements_at_a(stack_a, stack_b, &elements);
	else
		while (elements.element_to_end < elements.max_elem_to_op_b
			|| elements.element_pushed < elements.max_elem_to_op_a)
			merge_elements_at_b(stack_a, stack_b, &elements);
	update_counts(counts);
}
