/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_checkers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:35:32 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/03 13:35:33 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORDER_CHECKERS_H
# define ORDER_CHECKERS_H

# include "../dependencies/libft/libft.h"
# include "../dependencies/printf/ft_printf.h"

int	is_stack_ordered(t_list *stack);
int	is_stack_ordered_by_n_elements(t_list *stack, int n);
int	is_stack_ordered_until(t_list *stack, int ordered_until);

#endif