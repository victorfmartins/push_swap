/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:17:48 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/03 15:51:57 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (init_stack(argc, argv, &stack_a) != INIT_SUCCESS)
		return (INIT_ERROR);
	if (ft_lstsize(stack_a) < 15)
		order_small_list(&stack_a, &stack_b);
	else
		order_large_list(&stack_a, &stack_b);
	ft_lstclear(&stack_a, &free);
	ft_lstclear(&stack_b, &free);
}
