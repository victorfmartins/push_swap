/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_merger.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:33:02 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/03 13:34:15 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_MERGER_H
# define STACK_MERGER_H

# include "../dependencies/libft/libft.h"
# include "../dependencies/printf/ft_printf.h"

typedef struct s_elements
{
	int	element_pushed;
	int	element_to_end;
	int	max_elem_to_op_a;
	int	max_elem_to_op_b;
}				t_elements;

void	merge_stacks(t_list **stack_a, t_list **stack_b, int batch_case,
			t_counts *counts);

#endif