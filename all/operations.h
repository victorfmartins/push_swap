/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:18:05 by vfranco-          #+#    #+#             */
/*   Updated: 2022/09/29 15:03:22 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../.dependencies/libft/libft.h"
# include "../.dependencies/printf/ft_printf.h"

void swap(t_list **stack);

void rotate(t_list **stack);

void reverse_rotate(t_list **stack);

void push(t_list **stack_out, t_list **stack_in);

#endif