/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_alg_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:18:05 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/03 13:34:42 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMALL_ALG_UTILS_H
# define SMALL_ALG_UTILS_H

# include "../dependencies/libft/libft.h"
# include "../dependencies/printf/ft_printf.h"
# include "operations.h"
# include "push_swap_utils.h"

void	second_order_push_and_swap(t_list **stack_a, t_list **stack_b);
void	first_order_rotate(t_list **stack_a, t_list **stack_b);
void	first_order_swap(t_list **stack_a, t_list **stack_b);

#endif