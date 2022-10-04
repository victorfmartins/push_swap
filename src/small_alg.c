/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:37:29 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/03 13:37:30 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/small_alg.h"

static void	first_order(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && get_stack_content(*stack_a)
		> get_stack_content(ft_lstlast(*stack_a)))
	{
		rotate(stack_a, NULL);
		if (*stack_b && get_stack_content(*stack_b)
			< get_stack_content(ft_lstlast(*stack_b)))
			rotate(stack_b, "rr\n");
		else
			ft_printf("ra\n");
	}
	else if (*stack_a && (*stack_a)->next)
	{
		if (get_stack_content(*stack_a) > get_stack_content((*stack_a)->next))
			first_order_swap(stack_a, stack_b);
		else
			first_order_rotate(stack_a, stack_b);
	}
}

static void	second_order(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && *stack_b)
	{
		if ((*stack_a)->next && get_stack_content(*stack_a)
			< get_stack_content(*stack_b)
			&& get_stack_content((*stack_a)->next)
			> get_stack_content(*stack_b))
			second_order_push_and_swap(stack_a, stack_b);
		else if (get_stack_content(*stack_a) < get_stack_content(*stack_b))
			rotate(stack_a, "ra\n");
		else if (get_stack_content(*stack_a) > get_stack_content(*stack_b)
			&& get_stack_content(ft_lstlast(*stack_a))
			< get_stack_content(*stack_b))
			push(stack_b, stack_a, "pa\n");
		else if (get_stack_content(ft_lstlast(*stack_a))
			< get_stack_content(*stack_a)
			&& get_stack_content(ft_lstlast(*stack_a))
			> get_stack_content(*stack_b))
			reverse_rotate(stack_a, "rra\n");
		else if (get_stack_content(*stack_a) > get_stack_content(*stack_b))
			push(stack_b, stack_a, "pa\n");
	}
}

static void	third_order(t_list **stack_a)
{
	if (*stack_a)
		reverse_rotate(stack_a, "rra\n");
}

void	order_small_list(t_list **stack_a, t_list **stack_b)
{
	while (!is_stack_ordered(*stack_a))
	{
		first_order(stack_a, stack_b);
	}
	while (*stack_b)
	{
		second_order(stack_a, stack_b);
	}
	while (!is_stack_ordered(*stack_a))
	{
		third_order(stack_a);
	}
}
