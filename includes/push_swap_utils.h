/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:35:18 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/03 13:35:19 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef BATCH_SIZE
#  define BATCH_SIZE 3
# endif

# include "../dependencies/libft/libft.h"
# include "../dependencies/printf/ft_printf.h"

int	max(int nbr1, int nbr2);
int	min(int nbr1, int nbr2);
int	ft_power(int nbr_to_power, int power);
int	get_stack_content(t_list *stack);
int	first_is_greater_than_next(t_list *stack);

#endif