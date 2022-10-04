/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_alg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:18:05 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/03 03:34:14 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMALL_ALG_H
# define SMALL_ALG_H

# include "../dependencies/libft/libft.h"
# include "../dependencies/printf/ft_printf.h"
# include "small_alg_utils.h"
# include "order_checkers.h"

void	order_small_list(t_list **stack_a, t_list **stack_b);

#endif