/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_alg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:18:05 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/03 13:36:22 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LARGE_ALG_H
# define LARGE_ALG_H

# include "../dependencies/libft/libft.h"
# include "../dependencies/printf/ft_printf.h"
# include "large_alg_utils.h"
# include "push_swap_utils.h"
# include "order_checkers.h"
# include "stack_merger.h"

void	order_large_list(t_list **stack_a, t_list **stack_b);

#endif