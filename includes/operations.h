/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:18:05 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/03 13:35:49 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../dependencies/libft/libft.h"
# include "../dependencies/printf/ft_printf.h"

void	swap(t_list **stack, char *to_print);
void	rotate(t_list **stack, char *to_print);
void	reverse_rotate(t_list **stack, char *to_print);
void	push(t_list **stack_out, t_list **stack_in, char *to_print);

#endif