/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 05:25:22 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/03 02:51:37 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_utils.h"

int	max(int nbr1, int nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
}

int	min(int nbr1, int nbr2)
{
	if (nbr1 < nbr2)
		return (nbr1);
	return (nbr2);
}

int	ft_power(int nbr_to_power, int power)
{
	if (power == 0)
		return (1);
	return (nbr_to_power * ft_power(nbr_to_power, power - 1));
}

int	get_stack_content(t_list *stack)
{
	return (*((int *)(stack->content)));
}

int	first_is_greater_than_next(t_list *stack)
{
	if (get_stack_content(stack) > get_stack_content((stack)->next))
		return (TRUE);
	return (FALSE);
}
