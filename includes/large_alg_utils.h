/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_alg_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:18:05 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/03 13:36:08 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LARGE_ALG_UTILS_H
# define LARGE_ALG_UTILS_H

# include "../dependencies/libft/libft.h"
# include "../dependencies/printf/ft_printf.h"
# include "push_swap_utils.h"
# include "operations.h"

typedef struct s_counts
{
	int	count_n_a;
	int	count_n_b;
	int	na_case;
}				t_counts;

void	rotate_swap_reverse(t_list **stack_a, t_list **stack_b);
void	order_tree_elements(t_list **stack_a, t_list **stack_b);
int		max_elem_to_op(t_list *stack, int batch_case, int count_n);

#endif